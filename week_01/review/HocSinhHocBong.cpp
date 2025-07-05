#include "HocSinhHocBong.h"
#include <iostream>

HocSinhHocBong::HocSinhHocBong(std::string id, std::string name, int age, double gpa, double tienThuong) 
    : Student(id, name, age, gpa), tienThuong(tienThuong) { 
}

void HocSinhHocBong::display() const { 
    Student::display(); 
    if(gpa > 3.5) { 
        std::cout << "Hoc sinh nhan duoc hoc bong " << tienThuong << " VND" << std::endl;
    }
    else { 
        std::cout << "Hoc sinh chua du dieu kien de nhan hoc bong!" << std::endl; 
    }
}