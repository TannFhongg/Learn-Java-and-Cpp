#ifndef STUDENTFACTORY_H
#define STUDENTFACTORY_H

#include "Student.h"
#include "HocSinhHocBong.h"
#include <iostream>
#include <string>

class StudentFactory { 
    public:
    static Student* createStudent() { 
        std::cout << "Nhap id sinh vien:" ; 
        std::string id; 
        getline(std::cin,id); 
        std::cout <<"Nhap ten sinh vien: "; 
        std::string name; 
        getline(std::cin,name); 
        std::cout<< "Nhap tuoi sinh vien: "; 
        int age; std::cin >> age; 
        std::cout <<"Nhap gpa cua sinh vien: "; 
        double gpa; std::cin >> gpa; 

        if(gpa > 3.5) { 
            double tienThuong; 
            std::cout <<"Nhap so tien thuong: " ; std::cin >> tienThuong; std::cin.ignore(); 
            return new HocSinhHocBong(id, name, age, gpa, tienThuong); 
        }
        else { 
            return new Student(id,name,age,gpa); 
        }
    }
}; 

#endif // STUDENTFACTORY_H 