#include <iostream>
#include <fstream>
#include <string>
#include "Course.h"
#include "Date.h"
#include "AttendanceRecord.h"

using namespace std;

Course::Course(std::string id, std::string title, Date startTime, Date endTime) : startTime(startTime), endTime(endTime) {
  this->id = id;
  this->title = title;
}

std::string Course::getID() {
  return id;
}

std::string Course::getTitle() {
  return title;
}

Date Course::getStartTime() {
  return startTime;
}

Date Course::getEndTime() {
  return endTime;
}

void Course::addAttendanceRecord(AttendanceRecord ar) {
  if ((startTime <= ar.getDate()) && (endTime >= ar.getDate())) {
    attendanceRecords.push_back(ar);
  } else {
    cout << "did not save this record." << endl;
  }
}

void Course::outputAttendance() {
  if (attendanceRecords.empty()) {
    cout << "No Records" << endl;
  } else {
    for (std::size_t iterator = 0; iterator < attendanceRecords.size(); ++iterator) {
      cout << attendanceRecords[iterator].getDate().getDateTime() << "," 
      << attendanceRecords[iterator].getCourseID() << ","
      << attendanceRecords[iterator].getStudentID() << endl;
    }
  }
}

void Course::outputAttendance(std::string student_id) {
  if (attendanceRecords.empty()) {
    cout << "No Records" << endl;
  } else {
    bool noStudentRecords = true;
    for (std::size_t iterator = 0; iterator < attendanceRecords.size(); ++iterator) {
      if (attendanceRecords[iterator].getStudentID() == student_id) {
        noStudentRecords = false;
        cout << attendanceRecords[iterator].getDate().getDateTime() << "," 
        << attendanceRecords[iterator].getCourseID() << ","
        << attendanceRecords[iterator].getStudentID() << endl;
      }
    }
    if (noStudentRecords == true) {
      cout << "No Records" << endl;
    }
  }
}