#include <iostream>
#include <iomanip>
#include <sstream>
#include "School.h"
#include "SchoolMember.h"

using namespace std;

static string format_gpa(float gpa) {
    ostringstream oss;
    oss << fixed << setprecision(1) << gpa;
    return oss.str();
}

string SchoolMember::getName() const {
    return name;
}

string SchoolMember::getID() const {
    return id;
}

School* SchoolMember::getSchool() const {
    return school;
}

void Professor::addStudent(string id) {
    students.push_back(id);
}

void Professor::print() const {
    cout << getName() << "(" << getID() << ")" << endl;
    cout << "-- " << academic_rank << " Professor" << endl;
    cout << "-- Teach: ";
    if (students.empty()) {
        cout << "No Student" << endl;
    } else {
        for (int i = 0; i < (int)students.size(); i++) {
            if (i > 0) cout << ", ";
            SchoolMember* sm = getSchool()->getSchoolMember(students[i]);
            if (sm != nullptr) {
                cout << sm->getName() << "(" << students[i] << ")";
            } else {
                cout << students[i];
            }
        }
        cout << endl;
    }
}

float Student::getGPA() const {
    return gpa;
}

int UndergraduateStudent::getSemester() const {
    return semester;
}

void UndergraduateStudent::print() const {
    cout << getName() << "(" << getID() << ")" << endl;
    cout << "-- Undergraduate Student" << endl;
    cout << "-- GPA: " << format_gpa(getGPA()) << endl;
    cout << "-- Semester: " << semester << endl;
}

string GraduateStudent::getDegree() const {
    return degree;
}

void GraduateStudent::print() const {
    cout << getName() << "(" << getID() << ")" << endl;
    cout << "-- " << degree << ", Graduate Student" << endl;
    cout << "-- GPA: " << format_gpa(getGPA()) << endl;
}

int Alumni::getGraduateYear() const {
    return graduate_year;
}

void Alumni::print() const {
    cout << getName() << "(" << getID() << ")" << endl;
    cout << "-- Graduated in " << graduate_year << endl;
    cout << "-- GPA: " << format_gpa(getGPA()) << endl;
}
