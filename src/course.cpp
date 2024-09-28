#include "course.h"

#include <algorithm>

enum gradeFlags {
  Ungraded = -1,
  Missing = -2,
};

using std::string;
using std::unordered_map;
using std::vector;

// Constructor
Course::Course(int courseCRN, string courseName) {
  this->CRN = courseCRN;
  this->name = courseName;
}

int Course::getCRN() { return this->CRN; }

string Course::getName() { return this->name; }

unordered_map<string, unordered_map<int, int>> Course::getAssignments() {
  return this->assignments;
}

// Returns map of key UID and value grade
unordered_map<int, int> Course::getAssignmentGrades(string assignment) {
  auto assignmentIterator = this->assignments.find(assignment);

  // Return an empty map if the assignment doesn't exist
  if (assignmentIterator == this->assignments.end()) return {};

  return assignmentIterator->second;
}

vector<int> Course::getStudents() { return this->students; }

void Course::setCRN(int courseCRN) { this->CRN = courseCRN; }

void Course::setName(string courseName) { this->name = courseName; }

// Assignments
void Course::createAssignment(string assignment) {
  unordered_map<int, int> grades;
  for (size_t i = 0; i < this->students.size(); i++) {
    grades[students[i]] = Ungraded;
  }
  this->assignments[assignment] = grades;
}

void Course::deleteAssignment(string assignment) {
  this->assignments.erase(assignment);
}

void Course::gradeAssignment(int studentUID, string assignment, int grade) {
  if (!this->studentExists(studentUID)) return;

  this->assignments[assignment][studentUID] = grade;
}

// Students
void Course::addStudent(int studentUID) {
  auto it = std::find(this->students.begin(), this->students.end(), studentUID);

  // If the student already is in the class, return
  if (it != this->students.end()) return;

  this->students.push_back(studentUID);

  // Set student's assignments in the class to ungraded
  for (auto it = this->assignments.begin(); it != this->assignments.end();
       it++) {
    it->second[studentUID] = Ungraded;
  }
}

void Course::removeStudent(int studentUID) {
  auto it = std::find(this->students.begin(), this->students.end(), studentUID);

  // If the student is already not in the class, return
  if (it == this->students.end()) return;

  // Erase student's grades from the course
  for (auto it = this->assignments.begin(); it != this->assignments.end();
       it++) {
    it->second.erase(studentUID);
  }

  this->students.erase(it);
}

// PRIVATE

bool Course::studentExists(int studentUID) {
  bool exists = false;
  for (size_t i = 0; i < this->students.size(); i++) {
    if (students[i] == studentUID) exists = true;
  }

  return exists;
}