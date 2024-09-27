#include "gradebook.h"

#include <algorithm>

std::vector<std::pair<int, std::string>> Gradebook::getCourses() {
  std::vector<std::pair<int, std::string>> coursesInfo;
  for (size_t i = 0; i < this->courses.size(); i++) {
    coursesInfo.push_back({courses[i].getCRN(), courses[i].getName()});
  }

  return coursesInfo;
}

std::vector<std::pair<int, std::string>> Gradebook::getStudents() {
  std::vector<std::pair<int, std::string>> studentsInfo;
  for (size_t i = 0; i < this->students.size(); i++) {
    studentsInfo.push_back({students[i].getUID(), students[i].getName()});
  }

  return studentsInfo;
}

std::vector<std::pair<int, std::string>> Gradebook::getCourses(int studentUID) {
  std::vector<std::pair<int, std::string>> studentsCourses = {};
  Student* student = getStudent(studentUID);

  if (student == nullptr) return {};

  std::vector<int> courseCRNs = student->getCourses();

  // Gather all the course objects
  for (size_t i = 0; i < courseCRNs.size(); i++) {
    Course* course = getCourse(courseCRNs[i]);

    if (course != nullptr)
      studentsCourses.push_back({courseCRNs[i], course->getName()});
  }

  return studentsCourses;
}

std::vector<std::pair<int, std::string>> Gradebook::getStudents(int courseCRN) {
  std::vector<std::pair<int, std::string>> studentsInCourse = {};

  Course* course = getCourse(courseCRN);

  if (course == nullptr) return {};

  std::vector<int> studentUIDs = course->getStudents();

  for (size_t i = 0; i < studentsInCourse.size(); i++) {
    Student* student = getStudent(studentUIDs[i]);

    if (student != nullptr)
      studentsInCourse.push_back({studentUIDs[i], student->getName()});
  }

  return studentsInCourse;
}

std::string Gradebook::getCourseName(int courseCRN) {
  Course* course = getCourse(courseCRN);

  if (course == nullptr) return "";

  return course->getName();
}

std::string Gradebook::getStudentName(int studentUID) {
  Student* student = getStudent(studentUID);

  if (student == nullptr) return "";

  return student->getName();
}

float Gradebook::getGrade(int studentUID, int courseCRN) {
  Course* course = this->getCourse(courseCRN);

  if (course == nullptr) return -1;

  float sum = 0, totalGrades = 0;
  auto assignments = course->getAssignments();
  for (auto it = assignments.begin(); it != assignments.end(); it++) {
    auto& studentGrades = it->second;
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

  return grades;
}

std::vector<std::pair<std::string, int>> Gradebook::getStudentsGradesInCourse(
    int studentUID, int courseCRN) {
  Student* student = this->getStudent(studentUID);
  Course* course = this->getCourse(courseCRN);

  if (student == nullptr || course == nullptr) return {};

  std::vector<std::pair<std::string, int>> grades;
  auto assignments = course->getAssignments();
  for (auto it = assignments.begin(); it != assignments.end(); it++) {
    grades.push_back({it->first, it->second[studentUID]});
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

  return grades;
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

float Gradebook::getGPA(int studentUID) {
  Student* student = this->getStudent(studentUID);

  if (student == nullptr) return -1;

  float sum = 0;
  std::vector<int> studentsCourses = student->getCourses();
  size_t numOfCourses = studentsCourses.size();

  for (size_t i = 0; i < numOfCourses; i++) {
    sum += this->getGrade(studentUID, studentsCourses[i]);
  }

  return sum / numOfCourses;
}

void Gradebook::createCourse(int courseCRN, std::string courseName) {
  Course course(courseCRN, courseName);
  this->courses.push_back(course);
}

void Gradebook::createStudent(int studentUID, std::string studentName) {
  Student student(studentUID, studentName);
  this->students.push_back(student);
}

void Gradebook::addStudentToCourse(int studentUID, int courseCRN) {
  Student* student = nullptr;
  Course* course = nullptr;

  student = this->getStudent(studentUID);
  course = this->getCourse(courseCRN);

  if (student == nullptr || course == nullptr) return;

  student->addCourse(courseCRN);
  course->addStudent(studentUID);
}

void Gradebook::removeStudentFromCourse(int studentUID, int courseCRN) {
  Student* student = nullptr;
  Course* course = nullptr;

  student = this->getStudent(studentUID);
  course = this->getCourse(courseCRN);

  if (student == nullptr || course == nullptr) return;

  student->removeCourse(courseCRN);
  course->removeStudent(studentUID);
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