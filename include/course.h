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
  std::unordered_map<int, int> getAssignmentGrades(std::string assignment);
  std::vector<int> getStudents();
  int getCourseAverage();

  // Setters
  void setCRN(int courseCRN);
  void setName(std::string courseName);

  // Assignments
  void createAssignment(std::string assignment);
  void deleteAssignment(std::string assignment);

  void gradeAssignment(int studentUID, std::string assignment, int grade);

  // Students
  void addStudent(int studentUID);
  void removeStudent(int studentUID);

 private:
  bool studentExists(int studentUID);
  int CRN;
  std::string name;
  std::vector<int> students;

  // First key is by assignment, second is UID, result is grade
  std::unordered_map<std::string, std::unordered_map<int, int>> assignments;
};