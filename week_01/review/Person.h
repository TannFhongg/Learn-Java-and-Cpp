#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person { 
protected: 
    std::string name; 
    int age; 
public: 
    Person();
    Person(std::string name, int age);

    std::string getName() const ;
    int getAge();
    void setAge(int age);
    void setName(std::string name);
};

#endif // PERSON_H
