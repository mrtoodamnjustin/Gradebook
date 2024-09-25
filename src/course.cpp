#include "course.h"

// Constructors
Course::Course(int courseCRN, std::string courseName) {
  this->CRN = courseCRN;
  this->name = courseName;
}

// Course CRN
int Course::getCRN() { return this->CRN; }

void Course::setCRN(int courseCRN) { this->CRN = courseCRN; }

// Course Title
std::string Course::getName() { return this->name; }

void Course::setName(std::string courseName) { this->name = courseName; }

// Assignments
std::vector<std::string> Course::getAssignments() { return this->assignments; }

void Course::createAssignment(std::string assignment) {
  this->assignments.push_back(assignment);
}
void Course::deleteAssignment(int position) {}

// Students
std::vector<int> Course::getStudents() { return this->students; }

void Course::addStudent(int UID) { this->students.push_back(UID); }

void Course::removeStudent(int position) {
  this->students.erase(this->students.begin() + position);
}