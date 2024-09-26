#include "gradebook.h"

#include <algorithm>

Gradebook::Gradebook(std::vector<Course> courses) { this->courses = courses; }

std::vector<Course> Gradebook::getCourses() { return this->courses; }

std::vector<Student> Gradebook::getStudents() { return this->students; }

std::vector<Course> Gradebook::getCourses(int studentUID) {
  std::vector<Course> studentsCourses = {};
  Student* student = nullptr;

  // Find the student object, if it exists
  for (int i = 0; i < this->students.size(); i++) {
    if (this->students[i].getUID() == studentUID) {
      student = &students[i];
      break;
    }
  }

  if (student == nullptr) return {};

  std::vector<int> courseCRNs = student->getCourses();

  // Gather all the course objects
  for (int i = 0; i < courseCRNs.size(); i++) {
    for (int j = 0; j < this->courses.size(); j++) {
      if (this->courses[j].getCRN() == courseCRNs[i]) {
        studentsCourses.push_back(this->courses[j]);
        break;
      }
    }
  }

  return studentsCourses;
}

std::vector<Student> Gradebook::getStudents(int courseCRN) {
  std::vector<Student> studentsInCourse = {};
  Course* course = nullptr;

  for (int i = 0; i < this->courses.size(); i++) {
    if (this->courses[i].getCRN() == courseCRN) {
      course = &this->courses[i];
      break;
    }
  }

  if (course == nullptr) {
    return {};
  }

  std::vector<int> studentUIDs = course->getStudents();

  for (int i = 0; i < studentsInCourse.size(); i++) {
    for (int j = 0; j < this->students.size(); j++) {
      if (studentUIDs[i] == this->students[j].getUID())
        studentsInCourse.push_back(this->students[j]);
    }
  }

  return studentsInCourse;
}

int Gradebook::getGrade(int studentUID, int courseCRN) {}

// Returns vector of pair (class crn, grade)
std::vector<std::pair<int, int>> Gradebook::getStudentGrades(int studentUID) {}