#include "gradebook.h"

Gradebook::Gradebook(std::vector<Course> courses) { this->courses = courses; }

std::vector<Course> Gradebook::getCourses() { return this->courses; }