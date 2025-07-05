#include "Student.h"
#include <iostream>

Student::Student() : Person(), id(""), gpa(0.0) {}

Student::Student(std::string id, std::string name, int age, double gpa) : Person(name, age), id(id), gpa(gpa) {}

void Student::setId(std::string id)
{
    this->id = id;
}

void Student::setGpa(double gpa)
{
    this->gpa = gpa;
}

double Student::getGpa()
{
    return gpa;
}

std::string Student::getId() { 
    return id; 
}

Student::~Student() {}

void Student::display() const
{
    std::cout << "Id:" << id << " " << "Name : " << name << " " << "Age: " << age << " " << "Gpa: " << gpa << std::endl;
}