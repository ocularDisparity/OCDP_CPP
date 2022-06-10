#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Student.h"

using namespace std;

Student::Student(std::string student_id, std::string name) {
  id = student_id;
  this->name = name;
}

std::string Student::get_id() {
  return id;
}

std::string Student::get_name() {
  return name;
}

void Student::addCourse(std::string course_id) {
  bool exists = false;
  for (std::size_t iterator = 0; iterator < course_ids.size(); ++iterator) {
    if (course_ids[iterator] == course_id) {
      exists = true;
    }
  }
  if (exists == false) {
    course_ids.push_back(course_id);
  }
}

void Student::listCourses() {
  cout << "Courses for " << id << endl;
  for (std::size_t iterator = 0; iterator < course_ids.size(); ++iterator) {
    cout << course_ids[iterator] << endl;
  }
}