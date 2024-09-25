#pragma once

#include <string>
#include <vector>

#include "student.h"

class Course {
 public:
  // Constructor
  Course(int courseCRN, std::string courseTitle);

  // Getters
  int getCRN();
  std::string getCourse();
  std::vector<std::string> getAssignments();
  std::vector<int> getStudents();

  // Setters
  void setCRN(int courseCRN);
  void setCourse(std::string courseTitle);

  // Assignments
  void createAssignment(std::string assignment);
  void deleteAssignment(int position);

  // Students
  void addStudent(int UID);
  void removeStudent(int position);

 private:
  int CRN;
  std::string courseTitle;
  std::vector<int> students;
  // TODO: implement grades with a map?
  std::vector<std::string> assignments;
};