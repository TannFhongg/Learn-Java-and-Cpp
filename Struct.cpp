#include <iostream>
using namespace std;

struct Student {
    string name;
    int age;
    double gpa;

    // Constructor
    Student(string name, int age, double gpa) {
        this->name = name;
        this->age = age;
        this->gpa = gpa;
    }

    // Method (hàm thành viên)
    void display() {
        cout << "Name: " << name << ", Age: " << age << ", GPA: " << gpa << endl;
    }
};
void printStudent(Student s) {
    cout << "[By Value] Name: " << s.name << endl;
}

void changeGPA(Student &s) {
    s.gpa = 4.0;
}

int main() {
    Student s("Dat", 21, 3.7);

    
    printStudent(s); ; 
    changeGPA(s); 
    s.display();
    return 0;
}
