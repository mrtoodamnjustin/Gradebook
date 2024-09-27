#include <iostream>

#include "gradebook.h"
#include "utility.h"

enum Menu { MainMenu, AllStudentsMenu, AllClassesMenu, StudentMenu, ClassMenu };

int main() {
  Gradebook gradebook;
  std::cout
      << "==================================================================\n";
  std::cout
      << "  Welcome to my interactive gradebook! Please select an option:\n";
  std::cout
      << "==================================================================\n";
  Menu currentMenu = MainMenu;
  int currentID;
  while (true) {
    std::cout << "\n";
    std::cout << "To perform an action, enter the corresponding number.\n";
    std::cout << "Type 'q' to exit the program.\n";
    std::cout << "-----------------------------------------------\n";
    switch (currentMenu) {
      case MainMenu:
        std::cout << "[1]   See Classes\n";
        std::cout << "[2]   See Students\n";
        std::cout << "[3]   See About\n";
        break;

      case AllStudentsMenu: {
        auto students = gradebook.getStudents();
        utils::printEntities(students, "Student Name", "UID");
        if (students.empty()) std::cout << "No results.\n";
        std::cout << "-----------------------------------------------\n";
        std::cout << "[1]   Add New Student\n";
        std::cout << "[2]   Search Student by ID\n";
        std::cout << "[3]   Back to Main Menu\n";
        break;
      }

      case AllClassesMenu: {
        auto courses = gradebook.getCourses();
        utils::printEntities(courses, "Course Title", "CRN");
        if (courses.empty()) std::cout << "No results.\n";
        std::cout << "-----------------------------------------------\n";
        std::cout << "[1]   Add New Class\n";
        std::cout << "[2]   Search Class by ID\n";
        std::cout << "[3]   Back to Main Menu\n";
        break;
      }

      case StudentMenu: {
        auto studentGrades = gradebook.getStudentGrades(currentID);
        std::cout << "Classes\t\tGrades";
        for (size_t i = 0; i < studentGrades.size(); i++) {
          std::cout << gradebook.getCourseName(studentGrades[i].first) << "\t\t"
                    << gradebook.getGrade(currentID, studentGrades[i].first)
                    << "\n";
        }
        std::cout << "Student GPA: " << gradebook.getGPA(currentID);

        std::cout << "[1]   Add Class\n";
        std::cout << "[2]   Drop Class\n";
        std::cout << "[3]   View Class' Assignments\n";
        std::cout << "[4]   Return\n";
        break;
      }

      case ClassMenu: {
        auto studentGrades = gradebook.getCourseGrades(currentID);
        std::cout << gradebook.getCourseName(currentID) << " (" << currentID
                  << ")\n\n";

        int courseAverage = gradebook.getCourseAverageGrade(currentID);
        std::cout << "Course Average: "
                  << ((courseAverage != -1) ? std::to_string(courseAverage)
                                            : "nil")
                  << "\n";

        std::cout << "[1]   View Assignments\n";
        std::cout << "[2]   View Students\n";
        std::cout << "[3]   Return\n";
        break;
      }

      default:
        std::cout << "Err:  Invalid Menu Accessed...\n ";
    }
    std::cout << "-----------------------------------------------\n";

    std::string input;
    std::cin >> input;
    std::cout << "\n";

    if (input.size() == 1 && tolower(input.at(0)) == 'q') return 0;

    switch (currentMenu) {
      case MainMenu:
        switch (input.at(0)) {
          // See Classes
          case '1': {
            currentMenu = AllClassesMenu;
            break;
          }

          // See Students
          case '2': {
            currentMenu = AllStudentsMenu;
            break;
          }

          // See About
          case '3':
            utils::printAbout();
            break;

          default:
            utils::printBadInput();
            break;
        }
        break;

      case AllStudentsMenu: {
        auto students = gradebook.getStudents();
        utils::printEntities(students, "Student Name", "UID");

        switch (input.at(0)) {
          // Add New Student
          case '1': {
            std::string name;
            std::cout << "Enter the student's name: ";
            std::cin >> name;
            int studentUID = utils::getNumberInput("Enter the student's UID: ");
            gradebook.createStudent(studentUID, name);
            break;
          }

          // Search Student By UID
          case '2': {
            int studentUID = utils::getNumberInput("Enter the student's UID: ");
            currentID = studentUID;
            currentMenu = StudentMenu;
            break;
          }

          // Return To Main Menu
          case '3':
            currentMenu = MainMenu;
            break;

          default:
            utils::printBadInput();
            break;
        }
        break;
      }
      case AllClassesMenu: {
        auto courses = gradebook.getCourses();
        utils::printEntities(courses, "Course Title", "CRN");

        switch (input.at(0)) {
          // Add New Class
          case '1': {
            std::string name;
            std::cout << "Enter the course's name: ";
            std::cin >> name;
            int courseCRN = utils::getNumberInput("Enter the class's CRN: ");
            gradebook.createCourse(courseCRN, name);
            break;
          }
          // Search by ID
          case '2': {
            int currentCRN = utils::getNumberInput("Enter the class's CRN: ");
            currentID = currentCRN;
            currentMenu = ClassMenu;
            break;
          }

          // Return To Main Menu
          case '3':
            currentMenu = MainMenu;
            break;

          default:
            utils::printBadInput();
            break;
        }
        break;
      }

      case StudentMenu:
        switch (input.at(0)) {
          // Add Class
          case '1': {
            int courseCRN = utils::getNumberInput("Enter the class's CRN: ");
            gradebook.addStudentToCourse(currentID, courseCRN);
            break;
          }

          // Drop Class
          case '2': {
            int courseCRN = utils::getNumberInput("Enter the class's CRN: ");
            gradebook.removeStudentFromCourse(currentID, courseCRN);
            break;
          }

          // View Class' Assignments
          case '3': {
            int courseCRN = utils::getNumberInput("Enter the class's CRN: ");
            std::vector<std::pair<int, std::string>> grades =
                gradebook.getStudentsGradesInCourse(currentID, courseCRN);
            utils::printEntities(grades, "Assignment", "Grade");
            break;
          }

          // Return
          case '4':
            currentMenu = MainMenu;
            break;

          default:
            utils::printBadInput();
            break;
        }
        break;

      case ClassMenu:
        switch (input.at(0)) {
          // View Assignments
          case '1': {
            std::vector<std::string> assignments =
                gradebook.getCourseAssignments(currentID);

            std::cout << "Assignments: \n";
            for (std::string assignment : assignments) {
              std::cout << assignment << "\n";
            }
            break;
          }

          // View Students
          case '2': {
            auto students = gradebook.getStudents(currentID);

            // Set first int to grade instead of UID
            for (auto student : students) {
              student.first = gradebook.getGrade(student.first, currentID);
            }

            utils::printEntities(students, "Student Name", "Grade");
            break;
          }

          // Return
          case '3':
            currentMenu = MainMenu;
            break;

          default:
            utils::printBadInput();
            break;
        }
        break;
    }
  }
}