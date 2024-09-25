#pragma once
#include <string>
#include <vector>

#include "course.h"

class Gradebook {
 public:
  // Constructors
  Gradebook(std::vector<Course>);

  std::vector<Course> getCourses();
  // TODO: finish implementation

 private:
  std::vector<Course> courses;
  std::vector<Course> students;
};