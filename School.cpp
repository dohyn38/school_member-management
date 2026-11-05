#include <iostream>
#include "School.h"
#include "SchoolMember.h"

using namespace std;

School::~School() {
    for (auto& pair : school_members) {
        delete pair.second;
    }
    school_members.clear();
}

void School::addSchoolMember(SchoolMember* s) {
    school_members[s->getID()] = s;
}

SchoolMember* School::getSchoolMember(const string& id) {
    auto it = school_members.find(id);
    if (it != school_members.end()) {
        return it->second;
    }
    return nullptr;
}

void School::print() const {
    cout << "[" << name << "]" << endl;
    cout << ">> Established year: " << established << endl;

    SchoolMember* pres = nullptr;
    auto it = school_members.find(president);
    if (it != school_members.end()) {
        pres = it->second;
    }
    cout << ">> President: " << (pres ? pres->getName() : president) << endl;
    cout << ">> Number of school member: " << school_members.size() << endl;
    cout << endl;

    for (auto& pair : school_members) {
        pair.second->print();
        cout << endl;
    }
}
