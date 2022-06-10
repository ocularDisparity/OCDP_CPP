#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include "School.h"
#include "AttendanceRecord.h"

using namespace std;

void School::addCourses(std::string filename) {
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Unable to open file: " << filename << endl;
    return;
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    istringstream ss(line);
    // course ID
    string course_id;
    getline(ss, course_id, ',');
    // start hour
    string str_start_hour;
    getline(ss, str_start_hour, ':');
    // start minute
    string str_start_minute;
    getline(ss, str_start_minute, ',');
    // end hour
    string str_end_hour;
    getline(ss, str_end_hour, ':');
    // end minute
    string str_end_minute;
    getline(ss, str_end_minute, ',');
    // course name
    string course_title;
    getline(ss, course_title);
    if (!ss.fail()) {
      int int_start_hour = std::stoi(str_start_hour);
      int int_start_minute = std::stoi(str_start_minute);
      Date start_time = Date(int_start_hour, int_start_minute, 0);
      
      int int_end_hour = std::stoi(str_end_hour);
      int int_end_minute = std::stoi(str_end_minute);
      Date end_time = Date(int_end_hour, int_end_minute, 0);
      
      bool exists = false;
      for (std::size_t iterator = 0; iterator < courses.size(); ++iterator) {
        if (courses[iterator].getID() == course_id) {
          exists = true;
        }
      }
      if (exists == false) {
        courses.push_back(Course(course_id, course_title, start_time, end_time));
      }
    }
  }
}

void School::addStudents(std::string filename) {
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Unable to open file: " << filename << endl;
    return;
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    istringstream ss(line);
    string uin;
    getline(ss, uin, ',');
    string name;
    getline(ss, name);
    if (!ss.fail()) {
      bool exists = false;
      for (std::size_t iterator = 0; iterator < students.size(); ++iterator) {
        if (students[iterator].get_id() == uin) {
          exists = true;
        }
      }
      if (exists == false) {
        students.push_back(Student(uin, name));
      }
    }
  }
}

void School::addAttendanceData(std::string filename) {
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Unable to open file: " << filename << endl;
    return;
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    istringstream ss(line);
    // year
    string str_year;
    getline(ss, str_year, '-');
    // month
    string str_month;
    getline(ss, str_month, '-');
    // day
    string str_day;
    getline(ss, str_day, ' ');
    // hour
    string str_hour;
    getline(ss, str_hour, ':');
    // minute
    string str_minute;
    getline(ss, str_minute, ':');
    // second
    string str_second;
    getline(ss, str_second, ',');
    // course ID
    string course_id;
    getline(ss, course_id, ',');
    // student ID
    string student_id;
    getline(ss, student_id);
    if (!ss.fail()) {
      int int_year = std::stoi(str_year);
      int int_month = std::stoi(str_month);
      int int_day = std::stoi(str_day);
      int int_hour = std::stoi(str_hour);
      int int_minute = std::stoi(str_minute);
      int int_second = std::stoi(str_second);
      Date loggedTime = Date(int_year, int_month, int_day, 
                             int_hour, int_minute, int_second);
      
      int position = 0;
      for (std::size_t iterator = 0; iterator < courses.size(); ++iterator) {
        if (courses[iterator].getID() == course_id) {
          position = iterator;
        }
      }
      courses[position].addAttendanceRecord(AttendanceRecord(course_id, student_id, loggedTime));
    }
  }
}

void School::listCourses() {
  if (courses.empty()) {
    cout << "No Courses" << endl;
  } else {
    for(std::size_t i = 0; i < courses.size(); ++i) {
      cout << courses[i].getID() << ","
      << courses[i].getStartTime().getTime(false) << ","
      << courses[i].getEndTime().getTime(false) << ","
      << courses[i].getTitle() << endl;
    }
  }
}

void School::listStudents() {
  if (students.empty()) {
    cout << "No Students" << endl;
  } else {
    for(std::size_t i = 0; i < students.size(); ++i) {
      cout << students[i].get_id() << ","
      << students[i].get_name() << endl;
    }
  }
}

void School::outputCourseAttendance(std::string course_id) {
  if (courses.empty()) {
    cout << "No Records" << endl;
  } else {
    for (std::size_t iterator = 0; iterator < courses.size(); ++iterator) {
      if (courses[iterator].getID() == course_id) {
        courses[iterator].outputAttendance();
      }
    }
  }
}

void School::outputStudentAttendance(std::string student_id, std::string course_id) {
  if (courses.empty()) {
    cout << "No Records" << endl;
  } else {
    for (std::size_t iterator = 0; iterator < courses.size(); ++iterator) {
      if (courses[iterator].getID() == course_id) {
        courses[iterator].outputAttendance(student_id);
      }
    }
  }
}