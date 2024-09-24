#include "student.h"

student::student(std::string name, std::vector<float> grades) {
  this->name = name;
  this->grades = grades;
}

student::student(std::string name) { this->name = name; }

std::string student::getName() { return this->name; }

void student::setName(std::string name) { this->name = name; }

std::vector<float> student::getGrades() { return this->grades; }

void student::setGrade(int position, float grade) {
  this->grades.at(position) = grade;
}

// Make access safer using try/catch?
float student::getGrade(int position) { return this->grades.at(position); }

float student::getGPA() {
  float sum = 0;
  int size = this->grades.size();

  for (int i = 0; i < size; i++) {
    sum += grades.at(i);
  }

  return sum / size;
}