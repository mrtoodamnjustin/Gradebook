#include <cctype>
#include <iostream>

#include "gradebook.h"

enum Menu { MainMenu, Students, Classes, Student, Class };

void flushCin() {
  std::cin.clear();
  std::cin.ignore(256, '\n');
}

void printMenu(Menu menu) {
  std::cout << "===============================================\n";
  std::cout << "      Welcome! Please select an option:\n";
  std::cout << "===============================================\n";
  std::cout << "To perform an action, enter the corresponding number.\n";
  std::cout << "Type 'q' to exit the program.\n";
  std::cout << "-----------------------------------------------\n";
  switch (menu) {
    case MainMenu:
      std::cout << "[1]   See Classes\n";
      std::cout << "[2]   See Students\n";
      std::cout << "[3]   See About\n";
      break;

    case Students:
      std::cout << "[1]   Add New Student\n";
      std::cout << "[2]   View All Students\n";
      std::cout << "[3]   Search Student by ID\n";
      std::cout << "[4]   Back to Main Menu\n";
      break;

    case Classes:
      std::cout << "[1]   Add New Class\n";
      std::cout << "[2]   View All Classes\n";
      std::cout << "[3]   Search Class by ID\n";
      std::cout << "[4]   Back to Main Menu\n";
      break;

    case Student:
      std::cout << "[1]   View Grades\n";
      std::cout << "[2]   View Classes\n";
      std::cout << "[3]   Return\n";
      break;

    case Class:
      std::cout << "[1]   View Assignments\n";
      std::cout << "[2]   View Class Grades\n";
      std::cout << "[3]   View Students\n";
      std::cout << "[4]   Return\n";

    default:
      std::cout << "Err:  Invalid Menu Accessed...\n ";
  }
  std::cout << "-----------------------------------------------\n";
}

int main() {
  std::cout << "Welcome to Consumer Softproducts interactive C++ gradebook!\n";
  Menu currentMenu = MainMenu;
  while (true) {
    printMenu(currentMenu);

    std::string input;
    std::cin >> input;

    // TODO: Peform different switch cases depending on currentMenu?
    //       i.e. nested switch statement?
    switch (tolower(input.at(0))) {
      case 'q':
        // TODO: save grades?
        return 0;
        break;

      default:
        break;
    }
  }
}