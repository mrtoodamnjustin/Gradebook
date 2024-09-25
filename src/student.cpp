#include "student.h"

#include <algorithm>

Student::Student(int UID, std::string name) {
  this->UID = UID;
  this->name = name;
}

std::string Student::getName() { return this->name; }

void Student::setName(std::string name) { this->name = name; }

int Student::getUID() { return this->UID; }

void Student::setUID(int UID) { this->UID = UID; }

std::vector<int> Student::getCourses() { return this->courses; }

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

// TODO:
std::vector<float> Student::getGrades() {}

float Student::getGrade(int courseCRN) {}

float Student::getGPA() {
  int sum = 0;
  int numberOfCourses = this->courses.size();
  for (int i = 0; i < numberOfCourses; i++) {
    sum += getGrade(this->courses[i]);
  }

  return sum / numberOfCourses;
}