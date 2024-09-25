#include "student.h"

Student::Student(std::string name, int UID, std::vector<float> grades) {
  this->UID = UID;
  this->name = name;
  this->grades = grades;
}

Student::Student(std::string name, int UID) {
  this->name = name;
  this->UID = UID;
}

std::string Student::getName() { return this->name; }

void Student::setName(std::string name) { this->name = name; }

std::vector<float> Student::getGrades() { return this->grades; }

void Student::setGrade(int position, float grade) {
  this->grades.at(position) = grade;
}

// Make access safer using try/catch?
float Student::getGrade(int position) { return this->grades.at(position); }

float Student::getGPA() {
  float sum = 0;
  int size = this->grades.size();

  for (int i = 0; i < size; i++) {
    sum += grades.at(i);
  }

  return sum / size;
}