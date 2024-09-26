#include "gradebook.h"

#include <algorithm>

Gradebook::Gradebook(std::vector<Course> courses) { this->courses = courses; }

std::vector<Course> Gradebook::getCourses() { return this->courses; }

std::vector<Student> Gradebook::getStudents() { return this->students; }

std::vector<Course> Gradebook::getCourses(int studentUID) {
  std::vector<Course> studentsCourses = {};
  Student* student = nullptr;

  // Find the student object, if it exists
  for (size_t i = 0; i < this->students.size(); i++) {
    if (this->students[i].getUID() == studentUID) {
      student = &students[i];
      break;
    }
  }

  if (student == nullptr) return {};

  std::vector<int> courseCRNs = student->getCourses();

  // Gather all the course objects
  for (size_t i = 0; i < courseCRNs.size(); i++) {
    for (size_t j = 0; j < this->courses.size(); j++) {
      if (this->courses[j].getCRN() == courseCRNs[i]) {
        studentsCourses.push_back(this->courses[j]);
        break;
      }
    }
  }

  return studentsCourses;
}

std::vector<Student> Gradebook::getStudents(int courseCRN) {
  std::vector<Student> studentsInCourse = {};
  Course* course = nullptr;

  for (size_t i = 0; i < this->courses.size(); i++) {
    if (this->courses[i].getCRN() == courseCRN) {
      course = &this->courses[i];
      break;
    }
  }

  if (course == nullptr) {
    return {};
  }

  std::vector<int> studentUIDs = course->getStudents();

  for (size_t i = 0; i < studentsInCourse.size(); i++) {
    for (size_t j = 0; j < this->students.size(); j++) {
      if (studentUIDs[i] == this->students[j].getUID())
        studentsInCourse.push_back(this->students[j]);
    }
  }

  return studentsInCourse;
}

float Gradebook::getGrade(int studentUID, int courseCRN) {
  Course* course = nullptr;

  for (size_t i = 0; i < this->courses.size(); i++) {
    if (this->courses[i].getCRN() == courseCRN) course = &this->courses[i];
    break;
  }

  if (course == nullptr) return -1;

  float sum = 0, totalGrades = 0;
  auto assignments = course->getAssignments();
  for (auto i = assignments.begin(); i != assignments.end(); i++) {
    auto& studentGrades = i->second;
    auto studentIt = studentGrades.find(studentUID);

    if (studentIt != studentGrades.end()) {
      totalGrades++;
      sum += studentIt->second;
    }
  }

  return sum / totalGrades;
}

// Returns vector of pair (class crn, grade)
std::vector<std::pair<int, int>> Gradebook::getStudentGrades(int studentUID) {
  Student* student = this->getStudent(studentUID);
  std::vector<std::pair<int, int>> grades = {};

  if (student == nullptr) return {};

  std::vector<int> studentsCourseCRNS = student->getCourses();
  for (size_t i = 0; i < studentsCourseCRNS.size(); i++) {
    grades.push_back({studentsCourseCRNS[i],
                      this->getGrade(studentUID, studentsCourseCRNS[i])});
  }
}

std::vector<std::pair<int, int>> Gradebook::getCourseGrades(int courseCRN) {
  std::vector<std::pair<int, int>> grades = {};

  Course* course = this->getCourse(courseCRN);

  if (course == nullptr) return {};

  std::vector<int> students = course->getStudents();
  for (size_t i = 0; i < students.size(); i++) {
    float grade = getGrade(students[i], courseCRN);
    if (grade != -1) grades.push_back({students[i], grade});
  }
}

int Gradebook::getCourseAverageGrade(int courseCRN) {
  int sum = 0;
  Course* course = this->getCourse(courseCRN);

  if (course == nullptr) return -1;

  std::vector<int> students = course->getStudents();
  for (size_t i = 0; i < students.size(); i++) {
    sum += (float)getGrade(students[i], courseCRN) /
           course->getAssignments().size();
  }

  return sum / students.size();
}

Course Gradebook::createCourse(int courseCRN, std::string courseName) {
  Course course(courseCRN, courseName);
  this->courses.push_back(course);
}

Student Gradebook::createStudent(int studentUID, std::string studentName) {
  Student student(studentUID, studentName);
  this->students.push_back(student);
}

// PRIVATE
Student* Gradebook::getStudent(int studentUID) {
  Student* student = nullptr;

  for (size_t i = 0; i < this->students.size(); i++) {
    if (students[i].getUID() == studentUID) {
      student = &students[i];
      break;
    }
  }

  return student;
}

Course* Gradebook::getCourse(int courseCRN) {
  Course* course = nullptr;

  for (size_t i = 0; i < this->courses.size(); i++) {
    if (courses[i].getCRN() == courseCRN) {
      course = &courses[i];
      break;
    }
  }

  return course;
}