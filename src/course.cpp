#include "course.h"

// Constructors
Course::Course(std::string courseTitle) { this->courseTitle = courseTitle; }

Course::Course(std::string courseTitle, std::vector<Student> students) {
  this->courseTitle = courseTitle;
  this->students = students;
}

Course::Course(std::string courseTitle, std::vector<Student> students,
               std::vector<std::string> assignments) {
  this->courseTitle = courseTitle;
  this->students = students;
  this->assignments = assignments;
}

// Course Title
std::string Course::getCourse() { return this->courseTitle; }

void Course::setCourseTitle(std::string courseTitle) {
  this->courseTitle = courseTitle;
}

// Assignments
std::vector<std::string> Course::getAssignments() { return this->assignments; }

void Course::createAssignment(std::string assignment) {
  this->assignments.push_back(assignment);
}
void Course::deleteAssignment(int position) {}

// Students
std::vector<Student> Course::getStudents() { return this->students; }

void Course::addStudent(Student student) { this->students.push_back(student); }

void Course::removeStudent(int position) {
  this->students.erase(this->students.begin() + position);
}