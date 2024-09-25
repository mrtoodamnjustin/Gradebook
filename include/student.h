#pragma once
#include <string>
#include <vector>

class Student {
 public:
  Student(int UID, std::string name);

  std::string getName();
  void setName(std::string name);

  float getGPA();

  std::vector<float> getGrades();

  float getGrade(int courseCRN);

  std::vector<int> getCourses();

  void addCourse(int courseCRN);

  void removeCourse(int courseCRN);

  int getUID();

  void setUID(int UID);

 private:
  int UID;
  std::string name;
  std::vector<int> courses;
};