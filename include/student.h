#pragma once
#include <string>
#include <vector>

class Student {
 public:
  // Constructor
  Student(int studentUID, std::string studentname);

  // Getters
  int getUID();
  std::string getName();
  std::vector<int> getCourses();
  bool isInCourse(int courseCRN);

  // Setters
  void setUID(int studentUID);
  void setName(std::string studentname);

  // Student's courses
  void addCourse(int courseCRN);
  void removeCourse(int courseCRN);

 private:
  int UID;
  std::string name;
  std::vector<int> courses;
};