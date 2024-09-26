#include "course.h"

// Constructor
Course::Course(int courseCRN, std::string courseName) {
  this->CRN = courseCRN;
  this->name = courseName;
}

int Course::getCRN() { return this->CRN; }

std::string Course::getName() { return this->name; }

std::unordered_map<std::string, std::unordered_map<int, int>>
Course::getAssignments() {
  return this->assignments;
}

std::vector<int> Course::getStudents() { return this->students; }

void Course::setCRN(int courseCRN) { this->CRN = courseCRN; }

void Course::setName(std::string courseName) { this->name = courseName; }

// Assignments
void Course::createAssignment(std::string assignment) {
  this->assignments[assignment] = {};
}

void Course::deleteAssignment(std::string assignment) {
  this->assignments.erase(assignment);
}

// Students
void Course::addStudent(int UID) { this->students.push_back(UID); }

void Course::removeStudent(int position) {
  this->students.erase(this->students.begin() + position);
}
