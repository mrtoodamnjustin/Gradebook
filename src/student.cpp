#include "student.h"

#include <algorithm>

Student::Student(int studentUID, std::string studentName) {
  this->UID = studentUID;
  this->name = studentName;
}

int Student::getUID() { return this->UID; }

std::string Student::getName() { return this->name; }

std::vector<int> Student::getCourses() { return this->courses; }

bool Student::isInCourse(int courseCRN) {
  bool exists = false;
  for (size_t i = 0; i < this->courses.size(); i++) {
    if (courses[i] == courseCRN) {
      exists = true;
      break;
    }
  }
  return exists;
}

void Student::setUID(int studentUID) { this->UID = studentUID; }

void Student::setName(std::string studentName) { this->name = studentName; }

void Student::addCourse(int courseCRN) {
  if (std::find(this->courses.begin(), this->courses.end(), courseCRN) ==
      this->courses.end())
    this->courses.push_back(courseCRN);
}

void Student::removeCourse(int courseCRN) {
  auto iterator =
      std::find(this->courses.begin(), this->courses.end(), courseCRN);

  // If the CRN isn't found, return
  if (iterator == this->courses.end()) return;

  // Otherwise, remove the student from the course
  this->courses.erase(iterator);
}