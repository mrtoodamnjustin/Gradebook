#pragma once
#include <string>
#include <vector>

#include "student.h"

class Gradebook {
 public:
  // Constructors
  Gradebook(std::vector<Student> students,
            std::vector<std::string> assignments);
  Gradebook(std::vector<Student> students);

  // Assignments
  std::vector<std::string> getAssignments();
  void createAssignment(std::string assignment);
  void deleteAssignment(int position);

  // Students
  std::vector<Student> getStudents();
  void addStudent(Student student);
  void removeStudent(int position);

 private:
  std::vector<Student> students;
  std::vector<std::string> assignments;
};