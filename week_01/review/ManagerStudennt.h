#ifndef MANAGERSTUDENT_H
#define MANAGERSTUDENT_H

#include "AbstractManager.h"
#include "Student.h"
#include <iostream>
#include <list>
#include <memory>

class ManagerStudent : public AbstractManager {
private:
    std::list<std::unique_ptr<Student>> ls;  

public:
   
void addStudent(std::unique_ptr<Student> s) {
    ls.push_back(std::move(s));
}

   
    void displayAll() const override {
        for (const auto& s : ls) {
            s->display();
        }
    }

    
   
};

#endif // MANAGERSTUDENT_H
