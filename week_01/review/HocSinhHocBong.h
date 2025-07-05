#ifndef HOCSINHHOCBONG_H
#define HOCSINHHOCBONG_H

#include <iostream>
#include <string>
#include "Student.h"

class HocSinhHocBong : public Student { 

private: 
double tienThuong; 
public: 
HocSinhHocBong(std::string id, std::string name, int age, double gpa, double tienThuong);
void display() const override;
}; 

#endif // HOCSINHHOCBONG_H 