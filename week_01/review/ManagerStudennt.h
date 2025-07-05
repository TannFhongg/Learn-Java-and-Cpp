#ifndef MANAGERSTUDENT_H
#define MANAGERSTUDENT_H

#include "AbstractManager.h"
#include "Student.h"
#include <iostream>
#include <list>

class ManagerStudent : public AbstractManager
{
private:
    std::list<Student*> ls;

public:
    void addStudent(Student *s) override
    {
        ls.push_back(s);
    }
    void displayAll() override
    {
        for (Student *s : ls)
        {
            s->display();
        }
    }
    ~ManagerStudent()
    {
        for (Student *s : ls)
            delete s;
    }
};

#endif // MANAGERSTUDENT_H