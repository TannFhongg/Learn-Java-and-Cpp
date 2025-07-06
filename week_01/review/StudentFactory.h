#ifndef STUDENTFACTORY_H
#define STUDENTFACTORY_H

#include "Student.h"
#include "HocSinhHocBong.h"
#include <iostream>
#include <string>
#include <memory>

class StudentFactory { 
    public:
     static std::unique_ptr<Student> createStudent() { 
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
        std::cin.ignore(); 
        if(gpa > 3.5) { 
            double tienThuong; 
            std::cout <<"Nhap so tien thuong: " ; std::cin >> tienThuong; std::cin.ignore(); 
            return std::make_unique<HocSinhHocBong>(id, name, age, gpa, tienThuong); 
        }
        else { 
            return std::make_unique<Student>(id,name,age,gpa); 
        }
    }
}; 

#endif // STUDENTFACTORY_H 