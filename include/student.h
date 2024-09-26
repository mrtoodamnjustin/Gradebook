#pragma once
#include <string>
#include <vector>

class Student {
 public:
  // Constructor
  Student(int UID, std::string name);

  // Getters
  int getUID();
  std::string getName();
  std::vector<int> getCourses();

  // Setters
  void setUID(int UID);
  void setName(std::string name);

  // Student's courses
  void addCourse(int courseCRN);
  void removeCourse(int courseCRN);

 private:
  int UID;
  std::string name;
  std::vector<int> courses;
};