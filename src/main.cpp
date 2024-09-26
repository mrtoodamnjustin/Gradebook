#include <cctype>
#include <iostream>

#include "gradebook.h"
#include "student.h"

enum Menu { MainMenu, StudentMenu, ClassMenu };

void flushCin() {
  std::cin.clear();
  std::cin.ignore(256, '\n');
}

void printMenu(Menu menu) {
  std::cout << "To perform an action, simply enter the number for the actions "
               "provided below. Enter q to exit the program.\n";
  switch (menu) {
    case MainMenu:
      std::cout << "[0]\tSee Classes\n";
      std::cout << "[1]\tSee Students\n";
      std::cout << "[2]\tSee about\n";
      break;

    case StudentMenu:
      // TODO: print student related actions
      break;

    case ClassMenu:
      // TODO: print class related actions
      break;
  }
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