#include <iostream>

#include "gradebook.h"

enum Menu { MainMenu, AllStudentsMenu, AllClassesMenu, StudentMenu, ClassMenu };

void flushCin() {
  std::cin.clear();
  std::cin.ignore(256, '\n');
}

void printEntities(std::vector<std::pair<int, std::string>>& entitites,
                   std::string header1, std::string header2) {
  std::cout << header1 << "\t\t" << header2 << "\n\n";
  for (size_t i = 0; i < entitites.size(); i++) {
    std::cout << entitites[i].second << "\t\t\t" << entitites[i].first << "\n";
  }
}

void printAbout() {}

void printBadInput() {}

int main() {
  Gradebook gradebook;
  std::cout
      << "==================================================================\n";
  std::cout
      << "  Welcome to my interactive gradebook! Please select an option:\n";
  std::cout
      << "==================================================================\n";
  Menu currentMenu = MainMenu;
  Menu previousMenu;
  int currentID;
  while (true) {
    previousMenu = currentMenu;
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
        printEntities(students, "Student Name", "UID");
        if (students.empty()) std::cout << "No results.\n";
        std::cout << "-----------------------------------------------\n";
        std::cout << "[1]   Add New Student\n";
        std::cout << "[2]   Search Student by ID\n";
        std::cout << "[3]   Back to Main Menu\n";
        break;
      }

      case AllClassesMenu: {
        auto courses = gradebook.getCourses();
        printEntities(courses, "Course Title", "CRN");
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
        std::cout << "Classes\t\tGrades";
        for (size_t i = 0; i < studentGrades.size(); i++) {
          std::cout << gradebook.getCourseName(studentGrades[i].first) << "\t\t"
                    << gradebook.getGrade(currentID, studentGrades[i].first)
                    << "\n";
        }
        std::cout << "Course Average: "
                  << gradebook.getCourseAverageGrade(currentID);

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
            printAbout();
            break;

          default:
            printBadInput();
            break;
        }
        break;

      case AllStudentsMenu: {
        auto students = gradebook.getStudents();
        printEntities(students, "Student Name", "UID");

        switch (input.at(0)) {
          // Add New Student
          case '1': {
            int studentUID;
            std::string name;
            std::cout << "Enter the student's name: ";
            std::cin >> name;
            std::cout << "Enter the student's UID: ";
            std::cin >> studentUID;
            gradebook.createStudent(studentUID, name);
            break;
          }

          // Search Student By UID
          case '2':
            int studentUID;
            std::cout << "Enter the student's UID: \n";
            std::cin >> studentUID;
            currentID = studentUID;
            currentMenu = StudentMenu;
            break;

          // Return To Main Menu
          case '3':
            currentMenu = MainMenu;
            break;

          default:
            printBadInput();
            break;
        }
        break;
      }
      case AllClassesMenu: {
        auto courses = gradebook.getCourses();
        printEntities(courses, "Course Title", "CRN");

        switch (input.at(0)) {
          // Add New Class
          case '1': {
            int courseCRN;
            std::string name;
            std::cout << "Enter the course's name: ";
            std::cin >> name;
            std::cout << "Enter the course's CRN: ";
            std::cin >> courseCRN;
            gradebook.createCourse(courseCRN, name);
            break;
          }
          // Search by ID
          case '2':
            int currentCRN;
            std::cout << "Enter the class's CRN: \n";
            std::cin >> currentCRN;
            currentID = currentCRN;
            currentMenu = ClassMenu;
            break;

          // Return To Main Menu
          case '3':
            currentMenu = MainMenu;
            break;

          default:
            printBadInput();
            break;
        }
        break;
      }

      case StudentMenu:
        switch (input.at(0)) {
          // Add Class
          case '1':
            int courseCRN;
            std::cout << "Enter the course CRN: ";
            std::cin >> courseCRN;
            gradebook.addStudentToCourse(currentID, courseCRN);
            break;

          // Drop Class
          case '2':
            int courseCRN;
            std::cout << "Enter the course CRN: ";
            std::cin >> courseCRN;
            gradebook.removeStudentFromCourse(currentID, courseCRN);
            break;

          // View Class' Assignments
          case '3': {
            int courseCRN;
            std::cout << "Enter the course CRN: ";
            std::cin >> courseCRN;
            std::vector<std::pair<int, std::string>> grades =
                gradebook.getStudentsGradesInCourse(currentID, courseCRN);
            printEntities(grades, "Assignment", "Grade");
            break;
          }

          // Return
          case '4':
            currentMenu = previousMenu;
            break;

          default:
            printBadInput();
            break;
        }
        break;

      // TODO: implement
      case ClassMenu:
        switch (input.at(0)) {
          // View Assignments
          case '1':
            break;

          // View Students
          case '2':
            break;

          // Return
          case '3':
            currentMenu = previousMenu;
            break;

          default:
            printBadInput();
            break;
        }
        break;
    }
  }
}