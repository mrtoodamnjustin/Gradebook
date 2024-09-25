#pragma once
#include <string>
#include <vector>

class Student {
 public:
  Student(std::string name, std::vector<float> grades);

  Student(std::string name);

  std::string getName();
  void setName(std::string name);

  float getGPA();
  std::vector<float> getGrades();

  // Grade at index 'position' gets set to 'grade'
  void setGrade(int position, float grade);

  // Get grade at index 'position'
  float getGrade(int position);

 private:
  std::string name;
  std::vector<float> grades;
};