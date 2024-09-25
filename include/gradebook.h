#pragma once
#include <string>
#include <vector>

#include "student.h"

class Gradebook {
 public:
  // Constructors
  Gradebook(std::string courseTitle);
  Gradebook(std::string courseTitle, std::vector<Student> students);
  Gradebook(std::string courseTitle, std::vector<Student> students,
            std::vector<std::string> assignments);

  // Course Title
  std::string getCourse();
  void setCourseTitle(std::string courseTitle);

  // Assignments
  std::vector<std::string> getAssignments();
  void createAssignment(std::string assignment);
  void deleteAssignment(int position);

  // Students
  std::vector<Student> getStudents();
  void addStudent(Student student);
  void removeStudent(int position);

 private:
  std::string courseTitle;
  std::vector<Student> students;
  std::vector<std::string> assignments;
};