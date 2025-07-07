
#include "Person.h"


Person::Person() {}

Person::Person(std::string name, int age) {
    this->name = name;
    this->age = age;
}


void Person::setName(std::string name) {
    this->name = name; 
}

void Person::setAge(int age) {
    this->age = age;
}

std::string Person::getName() const {
    return name;
}

int Person::getAge() {
    return age;
}
