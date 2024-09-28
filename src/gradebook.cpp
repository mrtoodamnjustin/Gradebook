#include "gradebook.h"

#include <algorithm>

#include "utility.h"

using std::pair;
using std::string;
using std::unordered_map;
using std::vector;

Gradebook::Gradebook() {}

vector<pair<string, int>> Gradebook::getCourses() {
  vector<pair<string, int>> coursesInfo;
  for (size_t i = 0; i < this->courses.size(); i++) {
    coursesInfo.push_back({courses[i].getName(), courses[i].getCRN()});
  }

  return coursesInfo;
}

vector<pair<string, int>> Gradebook::getStudents() {
  vector<pair<string, int>> studentsInfo;
  for (size_t i = 0; i < this->students.size(); i++) {
    studentsInfo.push_back({students[i].getName(), students[i].getUID()});
  }

  return studentsInfo;
}

vector<pair<string, int>> Gradebook::getCourses(int studentUID) {
  vector<pair<string, int>> studentsCourses = {};
  Student* student = getStudent(studentUID);

  if (student == nullptr) return {};

  vector<int> courseCRNs = student->getCourses();

  // Gather all the course objects
  for (size_t i = 0; i < courseCRNs.size(); i++) {
    Course* course = getCourse(courseCRNs[i]);

    if (course != nullptr)
      studentsCourses.push_back({course->getName(), courseCRNs[i]});
  }

  return studentsCourses;
}

vector<pair<string, int>> Gradebook::getStudents(int courseCRN) {
  vector<pair<string, int>> studentsInCourse = {};

  Course* course = getCourse(courseCRN);

  if (course == nullptr) return {};

  vector<int> studentUIDs = course->getStudents();

  for (size_t i = 0; i < studentsInCourse.size(); i++) {
    Student* student = getStudent(studentUIDs[i]);

    if (student != nullptr)
      studentsInCourse.push_back({student->getName(), studentUIDs[i]});
  }

  return studentsInCourse;
}

string Gradebook::getCourseName(int courseCRN) {
  Course* course = getCourse(courseCRN);

  if (course == nullptr) return "";

  return course->getName();
}

string Gradebook::getStudentName(int studentUID) {
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
vector<pair<int, int>> Gradebook::getStudentGrades(int studentUID) {
  Student* student = this->getStudent(studentUID);
  vector<pair<int, int>> grades = {};

  if (student == nullptr) return {};

  vector<int> studentsCourseCRNS = student->getCourses();
  for (size_t i = 0; i < studentsCourseCRNS.size(); i++) {
    grades.push_back({studentsCourseCRNS[i],
                      this->getGrade(studentUID, studentsCourseCRNS[i])});
  }

  return grades;
}

// Returns vector<pair<grade, assignmet name>>
vector<pair<string, int>> Gradebook::getStudentsGradesInCourse(int studentUID,
                                                               int courseCRN) {
  Student* student = this->getStudent(studentUID);
  Course* course = this->getCourse(courseCRN);

  if (student == nullptr || course == nullptr) return {};

  vector<pair<string, int>> grades;
  auto assignments = course->getAssignments();
  for (auto it = assignments.begin(); it != assignments.end(); it++) {
    grades.push_back({it->first, it->second[studentUID]});
  }

  return grades;
}

vector<pair<int, int>> Gradebook::getCourseGrades(int courseCRN) {
  vector<pair<int, int>> grades = {};

  Course* course = this->getCourse(courseCRN);

  if (course == nullptr) return {};

  vector<int> students = course->getStudents();
  for (size_t i = 0; i < students.size(); i++) {
    float grade = getGrade(students[i], courseCRN);
    if (grade != -1) grades.push_back({students[i], grade});
  }

  return grades;
}

vector<string> Gradebook::getCourseAssignments(int courseCRN) {
  vector<string> assignments;

  Course* course = this->getCourse(courseCRN);

  if (course == nullptr) return {};

  auto assignmentMap = course->getAssignments();
  for (auto it = assignmentMap.begin(); it != assignmentMap.end(); it++) {
    assignments.push_back(it->first);
  }

  return assignments;
}

// Returns -1 if unsuccesful
int Gradebook::getCourseAverageGrade(int courseCRN) {
  int sum = 0;
  Course* course = this->getCourse(courseCRN);

  if (course == nullptr) return -1;

  vector<int> students = course->getStudents();

  if (students.size() == 0) return -1;

  for (size_t i = 0; i < students.size(); i++) {
    sum += (float)getGrade(students[i], courseCRN) /
           course->getAssignments().size();
  }

  return sum / students.size();
}

unordered_map<int, int> Gradebook::getAssignmentGrades(int courseCRN,
                                                       string assignment) {
  Course* course = this->getCourse(courseCRN);

  if (course == nullptr) return {};

  return course->getAssignmentGrades(assignment);
}

float Gradebook::getAssignmentMeanGrade(int courseCRN, string assignment) {
  Course* course = this->getCourse(courseCRN);

  if (course == nullptr) return -1;

  unordered_map<int, int> gradeMap = course->getAssignmentGrades(assignment);

  float gradeSum = 0;
  int totalStudents = gradeMap.size();

  // Divide by zero check
  if (totalStudents == 0) return -1;

  // Sum each student's grades by iterating through the map
  for (auto it = gradeMap.begin(); it != gradeMap.end(); it++) {
    gradeSum += it->second;
  }

  // Return the mean
  return gradeSum / totalStudents;
}

float Gradebook::getGPA(int studentUID) {
  Student* student = this->getStudent(studentUID);

  if (student == nullptr) return -1;

  float sum = 0;
  vector<int> studentsCourses = student->getCourses();
  size_t numOfCourses = studentsCourses.size();

  if (numOfCourses == 0) return -1;

  for (size_t i = 0; i < numOfCourses; i++) {
    sum += utils::getGradePoint(this->getGrade(studentUID, studentsCourses[i]));
  }

  return sum / numOfCourses;
}

void Gradebook::gradeAssignment(int studentUID, int courseCRN,
                                string assignment, int grade) {
  Student* student = this->getStudent(studentUID);
  Course* course = this->getCourse(courseCRN);

  if (student == nullptr || course == nullptr) return;

  if (!student->isInCourse(courseCRN)) return;

  course->gradeAssignment(studentUID, assignment, grade);
}

void Gradebook::createAssignment(string assignment, int courseCRN) {
  Course* course = this->getCourse(courseCRN);

  if (course == nullptr) return;

  course->createAssignment(assignment);
}

void Gradebook::deleteAssignment(string assignment, int courseCRN) {
  Course* course = this->getCourse(courseCRN);

  if (course == nullptr) return;

  course->deleteAssignment(assignment);
}

void Gradebook::createCourse(int courseCRN, string courseName) {
  Course course(courseCRN, courseName);
  this->courses.push_back(course);
}

void Gradebook::createStudent(int studentUID, string studentName) {
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