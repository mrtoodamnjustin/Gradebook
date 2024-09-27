#pragma once

#include <string>
#include <vector>

namespace utils {
void flushCin();

void printEntities(std::vector<std::pair<std::string, int>>& entitites,
                   std::string header1, std::string header2);

void printAbout();
void printBadInput();

int getNumberInput(std::string inputMessage);
}  // namespace utils