#include "gradebook.h"

// Constructors

Gradebook::Gradebook(std::string courseTitle) {
  this->courseTitle = courseTitle;
}
Gradebook::Gradebook(std::string courseTitle, std::vector<Student> students,
                     std::vector<std::string> assignments) {
  this->courseTitle = courseTitle;
  this->students = students;
}
Gradebook::Gradebook(std::string courseTitle, std::vector<Student> students) {
  this->courseTitle = courseTitle;
  this->students = students;
}

// Course Title
std::string Gradebook::getCourse() { return this->courseTitle; }

void Gradebook::setCourseTitle(std::string courseTitle) {
  this->courseTitle = courseTitle;
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