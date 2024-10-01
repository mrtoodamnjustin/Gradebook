#include <iostream>

#include "gradebook.h"
#include "utility.h"

using std::pair;
using std::string;
using std::unordered_map;
using std::vector;

enum Menu {
  MainMenu,
  AllStudentsMenu,
  AllClassesMenu,
  StudentMenu,
  ClassMenu,
  AssignmentsMenu,
  AssignmentMenu
};

int main() {
  Gradebook gradebook;
  Menu currentMenu = MainMenu;
  string currentAssignment;
  int currentID;
  int printHeader = 1, printAbout, printBadInput;

  while (true) {
    system("cls");
    if (printHeader) {
      printHeader = 0;
      std::cout << "==========================================================="
                   "=======\n";
      std::cout << "  Welcome to my interactive gradebook! Please select an "
                   "option:\n";
      std::cout << "==========================================================="
                   "=======\n";
    }
    if (printAbout) utils::printAbout();
    if (printBadInput) utils::printBadInput();
    printAbout = 0;
    printBadInput = 0;
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
        std::cout << "Classes\t\t\tGrades\n\n";
        for (size_t i = 0; i < studentGrades.size(); i++) {
          std::cout << gradebook.getCourseName(studentGrades[i].first) << " ("
                    << studentGrades[i].first << ")\t\t"
                    << gradebook.getGrade(currentID, studentGrades[i].first)
                    << "\n\n";
        }
        float GPA = gradebook.getGPA(currentID);
        std::cout << "\nStudent GPA: "
                  << ((GPA != -1) ? std::to_string(GPA) : "nil") << "\n";

        std::cout << "[1]   Add Class\n";
        std::cout << "[2]   Drop Class\n";
        std::cout << "[3]   View Class' Assignments\n";
        std::cout << "[4]   Return\n";
        break;
      }

      case ClassMenu: {
        int courseAverage = gradebook.getCourseAverageGrade(currentID);
        std::cout << gradebook.getCourseName(currentID) << " (" << currentID
                  << ")\n\n";
        std::cout << "Course Average: "
                  << ((courseAverage != -1) ? std::to_string(courseAverage)
                                            : "nil")
                  << "\n";

        std::cout << "[1]   View Assignments\n";
        std::cout << "[2]   View Students\n";
        std::cout << "[3]   Return\n";
        break;
      }

      case AssignmentsMenu: {
        auto assignments = gradebook.getCourseAssignments(currentID);

        // Print assignments
        for (size_t i = 0; i < assignments.size(); i++) {
          float meanGrade =
              gradebook.getAssignmentMeanGrade(currentID, assignments[i]);

          std::cout << assignments[i] << "\t\t"
                    << ((meanGrade != -1) ? std::to_string(meanGrade) : "nil")
                    << "\n";
        }

        std::cout << "[1]   View Assignment\n";
        std::cout << "[2]   Create Assignment\n";
        std::cout << "[3]   Delete Assignment\n";
        std::cout << "[4]   Return\n";
        break;
      }

      case AssignmentMenu: {
        std::cout << currentAssignment << "\n\n";
        std::cout << "Grades: \n";

        unordered_map<int, int> gradesMap =
            gradebook.getAssignmentGrades(currentID, currentAssignment);

        // Print name and grades
        for (auto it = gradesMap.begin(); it != gradesMap.end(); it++) {
          std::cout << gradebook.getStudentName(it->first) << "\t\t"
                    << it->second;
        }

        std::cout << "[1]   Grade Student\n";
        std::cout << "[2]   Return\n";
        break;
      }

      default:
        std::cout << "Err:  Invalid Menu Accessed...\n ";
    }
    std::cout << "-----------------------------------------------\n";

    string input;
    std::cin >> input;
    utils::flushCin();
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
            printAbout = 1;
            break;

          default:
            printBadInput = 1;
            break;
        }
        break;

      case AllStudentsMenu: {
        switch (input.at(0)) {
          // Add New Student
          case '1': {
            string name;
            std::cout << "Enter the student's name: ";
            std::getline(std::cin, name);
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
            printBadInput = 1;
            break;
        }
        break;
      }
      case AllClassesMenu: {
        switch (input.at(0)) {
          // Add New Class
          case '1': {
            string name;
            std::cout << "Enter the course's name: ";
            std::getline(std::cin, name);
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
            printBadInput = 1;
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
            vector<pair<string, int>> grades =
                gradebook.getStudentsGradesInCourse(currentID, courseCRN);
            utils::printEntities(grades, "Assignment", "Grade");
            break;
          }

          // Return
          case '4':
            currentMenu = AllStudentsMenu;
            break;

          default:
            printBadInput = 1;
            break;
        }
        break;

      case ClassMenu:
        switch (input.at(0)) {
          // View Assignments
          case '1':
            currentMenu = AssignmentsMenu;
            break;

          // View Students
          case '2': {
            vector<pair<string, int>> students =
                gradebook.getStudents(currentID);

            // Change uid to the student's grade
            for (pair<string, int> student : students) {
              student.second = gradebook.getGrade(student.second, currentID);
            }

            // Print pair <student, grade>
            utils::printEntities(students, "Student Name", "Grade");
            break;
          }

          // Return
          case '3':
            currentMenu = AllClassesMenu;
            break;

          default:
            printBadInput = 1;
            break;
        }
        break;

      case AssignmentsMenu:
        switch (input.at(0)) {
          // View Assignment
          case '1': {
            string assignment;
            std::cout << "Enter the assignment's name exactly as you see it:\n";
            std::cin >> assignment;
            currentAssignment = assignment;
            currentMenu = AssignmentMenu;
            break;
          }

          // Create Assignment
          case '2': {
            string assignment;
            std::cout << "Enter the assignment's name exactly as you see it:\n";
            std::cin >> assignment;
            gradebook.createAssignment(assignment, currentID);
            break;
          }

          // Delete Assignment
          case '3': {
            string assignment;
            std::cout << "Enter the assignment's name exactly as you see it:\n";
            std::cin >> assignment;
            gradebook.deleteAssignment(assignment, currentID);
            break;
          }

          // Return
          case '4':
            currentMenu = ClassMenu;
            break;

          default:
            printBadInput = 1;
            break;
        }
        break;

      case AssignmentMenu:
        switch (input.at(0)) {
          // Grade Student
          case '1': {
            int studentUID = utils::getNumberInput("Enter the student's UID: ");
            int grade = utils::getNumberInput("Enter the grade: ");
            gradebook.gradeAssignment(studentUID, currentID, currentAssignment,
                                      grade);
            break;
          }

          // Return
          case '2':
            currentMenu = AssignmentsMenu;
            break;

          default:
            printBadInput = 1;
            break;
        }
        break;
    }
  }
}