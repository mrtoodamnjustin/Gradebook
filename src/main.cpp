#include <iostream>

#include "gradebook.h"

enum Menu { MainMenu, AllStudentsMenu, AllClassesMenu, StudentMenu, ClassMenu };

void flushCin() {
  std::cin.clear();
  std::cin.ignore(256, '\n');
}

void printStudents(std::vector<std::pair<int, std::string>>& entitites) {
  std::cout << "Student Name:\t\tUID:\n";
  for (size_t i = 0; i < entitites.size(); i++) {
    std::cout << entitites[i].second << " \t\t(" << entitites[i].first << ")\n";
  }
}

void printClasses(std::vector<std::pair<int, std::string>>& entitites) {
  std::cout << "Course Title:\t\tCRN:\n";
  for (size_t i = 0; i < entitites.size(); i++) {
    std::cout << entitites[i].second << "\t\t(" << entitites[i].first << ")\n";
  }
}

void printAbout() {}

void printBadInput() {}

int main() {
  Gradebook gradebook;
  std::cout << "Welcome to Consumer Softproducts interactive C++ gradebook!\n";
  Menu currentMenu = MainMenu;
  int currentID;
  while (true) {
    std::cout << "\n";
    std::cout << "===============================================\n";
    std::cout << "      Welcome! Please select an option:\n";
    std::cout << "===============================================\n";
    std::cout << "To perform an action, enter the corresponding number.\n";
    std::cout << "Type 'q' to exit the program.\n";
    std::cout << "-----------------------------------------------\n";
    switch (currentMenu) {
      case MainMenu:
        std::cout << "[1]   See Classes\n";
        std::cout << "[2]   See Students\n";
        std::cout << "[3]   See About\n";
        break;

      case AllStudentsMenu:
        std::cout << "[1]   Add New Student\n";
        std::cout << "[2]   Search Student by ID\n";
        std::cout << "[3]   Back to Main Menu\n";
        break;

      case AllClassesMenu:
        std::cout << "[1]   Add New Class\n";
        std::cout << "[2]   Search Class by ID\n";
        std::cout << "[3]   Back to Main Menu\n";
        break;

      case StudentMenu:
        std::cout << "[1]   View Grades\n";
        std::cout << "[2]   View Classes\n";
        std::cout << "[3]   Return\n";
        break;

      case ClassMenu:
        std::cout << "[1]   View Assignments\n";
        std::cout << "[2]   View Students\n";
        std::cout << "[3]   Return\n";
        break;

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
            auto courses = gradebook.getCourses();
            printClasses(courses);
            currentMenu = AllClassesMenu;
            break;
          }

          // See Students
          case '2': {
            auto students = gradebook.getStudents();
            printStudents(students);
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
        printStudents(students);

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
        printClasses(courses);

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

      // TODO: implement
      case StudentMenu:

        switch (input.at(0)) {
          // View Grades
          case '1':
            break;

          // View Classes
          case '2':
            break;

          // Return
          case '3':
            break;

          default:
            printBadInput();
            break;
        }
        break;
      }
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
            break;

          default:
            printBadInput();
            break;
        }
        break;
    }
  }
}