#include "gradebook.h"

// Constructors

Gradebook::Gradebook(std::vector<Student> students,
                     std::vector<std::string> assignments) {
  this->students = students;
}
Gradebook::Gradebook(std::vector<Student> students) {
  this->students = students;
}

// Assignments

std::vector<std::string> Gradebook::getAssignments() {
  return this->assignments;
}

void Gradebook::createAssignment(std::string assignment) {
  this->assignments.push_back(assignment);
}
void Gradebook::deleteAssignment(int position) {}

// Students

std::vector<Student> Gradebook::getStudents() { return this->students; }

void Gradebook::addStudent(Student student) {
  this->students.push_back(student);
}

void Gradebook::removeStudent(int position) {
  this->students.erase(this->students.begin() + position);
}