#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "student.h"

class Course {
 public:
  // Constructor
  Course(int courseCRN, std::string courseTitle);

  // Getters
  int getCRN();
  std::string getName();
  std::vector<std::string> getAssignments();
  std::vector<int> getStudents();
  int getCourseAverage();

  // Setters
  void setCRN(int courseCRN);
  void setName(std::string courseName);

  // Assignments
  void createAssignment(std::string assignment);
  void deleteAssignment(int position);

  // Students
  void addStudent(int UID);
  void removeStudent(int position);

 private:
  int CRN;
  std::string name;
  std::vector<int> students;

  // TODO: implement grades with a map?
  std::vector<std::string> assignments;

  // First key is by assignment, second is UID
  std::unordered_map<std::string, std::unordered_map<int, int>> grades;
};