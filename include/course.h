#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class Course {
 public:
  // Constructor
  Course(int courseCRN, std::string courseTitle);

  // Getters
  int getCRN();
  std::string getName();
  std::unordered_map<std::string, std::unordered_map<int, int>>
  getAssignments();
  std::vector<int> getStudents();
  int getCourseAverage();

  // Setters
  void setCRN(int courseCRN);
  void setName(std::string courseName);

  // Assignments
  void createAssignment(std::string assignment);
  void deleteAssignment(std::string assignment);

  // Students
  void addStudent(int studentUID);
  void removeStudent(int studentUID);

 private:
  int CRN;
  std::string name;
  std::vector<int> students;

  // First key is by assignment, second is UID, result is grade
  std::unordered_map<std::string, std::unordered_map<int, int>> assignments;
};