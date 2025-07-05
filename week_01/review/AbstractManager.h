#ifndef ABSTRACTMANAGER_H
#define ABSTRACTMANAGER_H

#include <iostream> 
#include "Student.h"

class AbstractManager {
    public:
     virtual void addStudent(Student* s) = 0; 
     virtual void displayAll() = 0;
     virtual ~AbstractManager() {}
 }; 

#endif // ABSTRACTMANAGER_H 