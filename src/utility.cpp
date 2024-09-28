#include "utility.h"

#include <iostream>
#include <string>

using std::string;

namespace utils {
void flushCin() {
  std::cin.clear();
  std::cin.ignore(256, '\n');
}

std::string toString(const std::string& value) { return value; }

void printAbout() {
  std::cout << "\n";
  std::cout << "======================== About ========================\n";
  std::cout << "Interactive Gradebook Program\n";
  std::cout << "Version: 1.0\n";
  std::cout << "Developed by: Justin Luque\n";
  std::cout
      << "Purpose: This program allows users to manage students, classes,\n";
  std::cout << "         and their grades in an interactive manner.\n";
  std::cout << "========================================================\n";
  std::cout << "\n";
}

void printBadInput() {
  std::cout << "\n";
  std::cout << "Invalid input. Please enter a valid option from the menu.\n";
  std::cout << "\n";
}

int getNumberInput(string inputMessage) {
  int input;
  std::cout << inputMessage;
  std::cin >> input;
  return input;
}

float getGradePoint(int grade) {
  if (grade >= 90)
    return 4.0;

  else if (grade >= 80)
    return 3.0;

  else if (grade >= 70)
    return 2.0;

  else if (grade >= 60)
    return 1.0;

  else
    return 0.0;
}
}  // namespace utils