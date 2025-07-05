#include "ManagerStudennt.h"
#include <iostream> 
#include "StudentFactory.h" 
#include "Student.h"
int main() { 

    ManagerStudent st; 
    std::cout << "Nhap so luong sinh vien: "; 

    int n; std::cin >> n; std::cin.ignore(); 
    for (int  i = 0; i < n; i++)
    {
        Student *s = StudentFactory::createStudent(); 
        st.addStudent(s); 
    }
    std::cout << "List of sinh vien: " << std::endl; 
    st.displayAll(); 
    return 0; 
}



