#include "utility.h"

#include <iostream>
#include <string>
#include <vector>

namespace utils {
void flushCin() {
  std::cin.clear();
  std::cin.ignore(256, '\n');
}

void printEntities(std::vector<std::pair<std::string, int>>& entitites,
                   std::string header1, std::string header2) {
  std::cout << header1 << "\t\t" << header2 << "\n\n";
  for (size_t i = 0; i < entitites.size(); i++) {
    std::cout << entitites[i].first << "\t\t\t" << entitites[i].second << "\n";
  }
}

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

int getNumberInput(std::string inputMessage) {
  int input;
  std::cout << inputMessage;
  std::cin >> input;
  return input;
}
}  // namespace utils