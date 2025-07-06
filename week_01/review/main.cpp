#include "ManagerStudennt.h"
#include <iostream> 
#include "StudentFactory.h" 
#include "Student.h"
#include <memory>

int main() { 

    auto st = std::make_unique<ManagerStudent>(); 
    std::cout << "Nhap so luong sinh vien: "; 

    int n; std::cin >> n; std::cin.ignore(); 
    for (int  i = 0; i < n; i++)
    {
        std::unique_ptr<Student> s = StudentFactory::createStudent(); 
        st ->addStudent(std::move(s)); 
    }
    std::cout << "List of sinh vien: " << std::endl; 
    st ->displayAll(); 
    return 0; 
}



