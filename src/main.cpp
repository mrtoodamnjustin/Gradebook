#include <cctype>
#include <iostream>

#include "gradebook.h"
#include "student.h"

void flushCin() {
  std::cin.clear();
  std::cin.ignore(256, '\n');
}

int main() {
  std::cout << "Welcome to Consumer Softproducts interactive C++ gradebook!\n";
  while (true) {
    // TODO: print menu from class

    std::string input;
    std::cout << "Please enter an action (q to exit).\n";
    std::cin >> input;

    switch (tolower(input.at(0))) {
      case 'q':
        // TODO: save grades?
        return 0;
        break;

      // TODO: detail out interface after completing class implementations
      default:
        break;
    }
  }
}