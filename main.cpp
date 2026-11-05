#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "School.h"
#include "SchoolMember.h"

using namespace std;

static void strip_cr(string& s) {
    if (!s.empty() && s.back() == '\r')
        s.pop_back();
}

vector<string> split(const string& line) {
    vector<string> result;
    size_t start = 0;
    size_t pos;

    while ((pos = line.find(',', start)) != string::npos) {
        result.push_back(line.substr(start, pos - start));
        start = pos + 1;
    }
    result.push_back(line.substr(start));

    return result;
}

int main() {
    ifstream ifs("input.txt");
    string line;

    getline(ifs, line);

    getline(ifs, line);
    strip_cr(line);

    vector<string> school_info = split(line);
    School* school = new School(school_info[1], stoi(school_info[2]), school_info[0]);

    getline(ifs, line);
    getline(ifs, line);

    while (getline(ifs, line)) {
        strip_cr(line);
        if (line == "")
            break;

        vector<string> prof_info = split(line);
        Professor* prof = new Professor(school, prof_info[0], prof_info[1], prof_info[2]);

        for (int i = 3; i < (int)prof_info.size(); i++) {
            prof->addStudent(prof_info[i]);
        }

        school->addSchoolMember(prof);
    }

    getline(ifs, line);

    while (getline(ifs, line)) {
        strip_cr(line);
        if (line == "")
            break;

        vector<string> stu_info = split(line);
        string type = stu_info[0];
        string id   = stu_info[1];
        string name = stu_info[2];
        float  gpa  = stof(stu_info[3]);

        if (type == "U") {
            int semester = stoi(stu_info[4]);
            school->addSchoolMember(new UndergraduateStudent(school, id, name, gpa, semester));
        } else if (type == "G") {
            string degree = stu_info[4];
            school->addSchoolMember(new GraduateStudent(school, id, name, gpa, degree));
        } else if (type == "A") {
            int graduate_year = stoi(stu_info[4]);
            school->addSchoolMember(new Alumni(school, id, name, gpa, graduate_year));
        }
    }

    ifs.close();

    school->print();
    delete school;

    return 0;
}
