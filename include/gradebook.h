#pragma once
#include <string>
#include <vector>

#include "course.h"
#include "student.h"

class Gradebook {
 public:
  // Constructors
  Gradebook(std::vector<Course>);

  std::vector<Course> getCourses();
  std::vector<Student> getStudents();

  std::vector<Course> getCourses(int studentUID);
  std::vector<Student> getStudents(int courseCRN);

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