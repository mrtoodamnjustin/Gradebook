#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

namespace utils {
void flushCin();

// Helper function to convert any type to string
template <typename T>
std::string toString(const T& value) {
  std::ostringstream oss;
  oss << value;
  return oss.str();
}

// Specialization for std::string to avoid extra conversion
std::string toString(const std::string& value);

// print vector of pairs of any type
template <typename T1, typename T2>
void printEntities(std::vector<std::pair<T1, T2>>& entities,
                   std::string header1, std::string header2) {
  int greatestLen = header1.length();

  for (size_t i = 0; i < entities.size(); i++) {
    int len = toString(entities[i].first).size();
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

// print unordered_map of any two types
template <typename T1, typename T2>
void printEntities(std::unordered_map<T1, T2>& entities, std::string header1,
                   std::string header2) {
  int greatestLen = header1.length();

  for (auto it = entities.begin(); it != entities.end(); it++) {
    int len = toString(it->first).size();
    if (len > greatestLen) {
      greatestLen = len;
    }
  }

  int width = std::max(20, greatestLen + 6);
  std::cout << std::left << std::setw(width) << header1 << header2 << "\n\n";
  for (auto it = entities.begin(); it != entities.end(); it++) {
    std::cout << std::left << std::setw(width) << it->first << it->second
              << "\n";
  }
}

void printAbout();
void printBadInput();

int getNumberInput(std::string inputMessage);

float getGradePoint(int grade);
}  // namespace utils