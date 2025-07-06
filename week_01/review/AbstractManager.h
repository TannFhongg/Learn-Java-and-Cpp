#ifndef ABSTRACTMANAGER_H
#define ABSTRACTMANAGER_H

#include <iostream> 
#include "Student.h"
#include <memory>

class AbstractManager {
    public:
     virtual void addStudent(std::unique_ptr<Student>(s)) = 0; 
     virtual void displayAll() const = 0;
     virtual ~AbstractManager() {}
 }; 

#endif // ABSTRACTMANAGER_H 