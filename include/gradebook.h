#pragma once
#include <string>
#include <vector>

#include "course.h"
#include "student.h"

class Gradebook {
 public:
  Gradebook();
  std::vector<std::pair<std::string, int>> getCourses();
  std::vector<std::pair<std::string, int>> getStudents();

  // Get student's courses
  std::vector<std::pair<std::string, int>> getCourses(int studentUID);
  // Get course's students
  std::vector<std::pair<std::string, int>> getStudents(int courseCRN);

  std::string getCourseName(int courseCRN);
  std::string getStudentName(int studentUID);

  float getGrade(int studentUID, int courseCRN);

  // Returns vector of pair<courseCRN, grade>
  std::vector<std::pair<int, int>> getStudentGrades(int studentUID);

  std::vector<std::pair<std::string, int>> getStudentsGradesInCourse(
      int studentUID, int courseCRN);

  // Returns vector of pair<studentUID, grade>
  std::vector<std::pair<int, int>> getCourseGrades(int courseCRN);

  std::vector<std::string> getCourseAssignments(int courseCRN);

  int getCourseAverageGrade(int courseCRN);

  float getGPA(int studentUID);

  void gradeAssignment(int studentUID, int courseCRN, std::string assignment,
                       int grade);

  void createAssignment(std::string assignment, int courseCRN);

  void deleteAssignment(std::string assignment, int courseCRN);

  void createCourse(int courseCRN, std::string courseName);

  void createStudent(int studentUID, std::string studentName);

  void addStudentToCourse(int studentUID, int courseCRN);

  void removeStudentFromCourse(int studentUID, int courseCRN);

 private:
  Student* getStudent(int studentUID);
  Course* getCourse(int courseCRN);

  std::vector<Course> courses;
  std::vector<Student> students;
};