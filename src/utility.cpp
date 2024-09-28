#include "utility.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using std::pair;
using std::string;
using std::vector;

namespace utils {
void flushCin() {
  std::cin.clear();
  std::cin.ignore(256, '\n');
}

void printEntities(vector<pair<string, int>>& entities, string header1,
                   string header2) {
  int greatestLen = header1.length();

  for (size_t i = 0; i < entities.size(); i++) {
    int len = entities[i].first.size();
    if (len > greatestLen) {
      greatestLen = len;
    }
  }

  int width = std::max(20, greatestLen + 6);
  std::cout << std::left << std::setw(width) << header1 << header2 << "\n\n";
  for (size_t i = 0; i < entities.size(); i++) {
    std::cout << std::left << std::setw(width) << entities[i].first
              << entities[i].second << "\n";
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