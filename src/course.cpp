#include "course.h"

enum gradeFlags {
  Ungraded = -1,
  Missing = -2,
};

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
  std::unordered_map<int, int> grades;
  for (size_t i = 0; i < this->students.size(); i++) {
    grades[students[i]] = Ungraded;
  }
  this->assignments[assignment] = grades;
}

void Course::deleteAssignment(std::string assignment) {
  this->assignments.erase(assignment);
}

// Students
void Course::addStudent(int studentUID) {
  this->students.push_back(studentUID);
}

void Course::removeStudent(int position) {
  this->students.erase(this->students.begin() + position);
}
