#pragma once
#include <map>
#include <string>

class SchoolMember;

class School {
private:
    std::string name;
    const int established;
    std::string president;
    std::map<std::string, SchoolMember*> school_members;

public:
    School(const std::string& name, int year, const std::string& prof)
        : name(name), established(year), president(prof) {}
    ~School();

    void print() const;
    void addSchoolMember(SchoolMember* s);
    SchoolMember* getSchoolMember(const std::string& id);
};
