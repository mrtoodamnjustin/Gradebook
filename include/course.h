#pragma once

#include <string>
#include <vector>

#include "student.h"

class Course {
 public:
  // Constructors
  Course(int courseCRN, std::string courseTitle);

  // Course CRN
  int getCRN();
  void setCRN(int courseCRN);

  // Course Title
  std::string getCourse();
  void setCourseTitle(std::string courseTitle);

  // Assignments
  std::vector<std::string> getAssignments();
  void createAssignment(std::string assignment);
  void deleteAssignment(int position);

  // Students
  std::vector<int> getStudents();
  void addStudent(int UID);
  void removeStudent(int position);

 private:
  int CRN;
  std::string courseTitle;
  std::vector<int> students;
  // TODO: implement grades with a map?
  std::vector<std::string> assignments;
};