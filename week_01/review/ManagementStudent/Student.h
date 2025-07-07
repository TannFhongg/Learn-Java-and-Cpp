#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "Person.h"

class Student : public Person
{

protected:
    std::string id;
    double gpa;

public:
    void setId(std::string id);
    void setGpa(double gpa);
    std::string getId();
    double getGpa();
    Student();
    Student(std::string id, std::string name, int age, double gpa);
    virtual void display() const;
    virtual ~Student();
};

#endif // STUDENT_H