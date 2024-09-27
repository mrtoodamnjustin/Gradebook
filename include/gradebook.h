#pragma once
#include <string>
#include <vector>

#include "course.h"
#include "student.h"

class Gradebook {
 public:
  std::vector<std::pair<int, std::string>> getCourses();
  std::vector<std::pair<int, std::string>> getStudents();

  std::vector<std::pair<int, std::string>> getCourses(int studentUID);
  std::vector<std::pair<int, std::string>> getStudents(int courseCRN);

  float getGrade(int studentUID, int courseCRN);

  // Returns vector of pair<courseCRN, grade>
  std::vector<std::pair<int, int>> getStudentGrades(int studentUID);

  // Returns vector of pair<studentUID, grade>
  std::vector<std::pair<int, int>> getCourseGrades(int courseCRN);

  int getCourseAverageGrade(int courseCRN);

  void createCourse(int courseCRN, std::string courseName);

  void createStudent(int studentUID, std::string studentName);
  // TODO: finish implementation

 private:
  Student* getStudent(int studentUID);
  Course* getCourse(int courseCRN);

  std::vector<Course> courses;
  std::vector<Student> students;
};