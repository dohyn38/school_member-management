#pragma once
#include <vector>
#include <string>

class School;

class SchoolMember {
private:
    std::string name;
    std::string id;
    School* school;

public:
    SchoolMember(const std::string& id, const std::string& name, School* school)
        : id(id), name(name), school(school) {}
    virtual ~SchoolMember() {}

    virtual void print() const = 0;
    std::string getName() const;
    std::string getID() const;
    School* getSchool() const;
};

class Professor : public SchoolMember {
private:
    std::string academic_rank;
    std::vector<std::string> students;

public:
    Professor(School* school, const std::string id, const std::string name, const std::string rank)
        : SchoolMember(id, name, school), academic_rank(rank) {}
    virtual ~Professor() {}

    void addStudent(std::string id);
    virtual void print() const;
};

class Student : public SchoolMember {
private:
    float gpa;

public:
    Student(School* school, const std::string& id, const std::string& name, float gpa)
        : SchoolMember(id, name, school), gpa(gpa) {}
    virtual ~Student() {}

    float getGPA() const;
    virtual void print() const = 0;
};

class UndergraduateStudent : public Student {
private:
    int semester;

public:
    UndergraduateStudent(School* school, const std::string& id, const std::string& name, float gpa, int semester)
        : Student(school, id, name, gpa), semester(semester) {}
    virtual ~UndergraduateStudent() {}

    int getSemester() const;
    virtual void print() const;
};

class GraduateStudent : public Student {
private:
    std::string degree;

public:
    GraduateStudent(School* school, const std::string& id, const std::string& name, float gpa, const std::string& degree)
        : Student(school, id, name, gpa), degree(degree) {}
    virtual ~GraduateStudent() {}

    std::string getDegree() const;
    virtual void print() const;
};

class Alumni : public Student {
private:
    int graduate_year;

public:
    Alumni(School* school, const std::string& id, const std::string& name, float gpa, int graduate_year)
        : Student(school, id, name, gpa), graduate_year(graduate_year) {}
    virtual ~Alumni() {}

    int getGraduateYear() const;
    virtual void print() const;
};
