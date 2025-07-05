#pragma once
#include <iostream>


class Sensor { 
    public:
    virtual void update() = 0; 
    virtual void display() const= 0; 
    virtual bool isAlert() const = 0; 
    virtual std::string getName() const =0;
    virtual ~Sensor(); 
};

