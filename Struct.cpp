#include <iostream>
using namespace std;

struct Student {
    string name;
    int age;
    double gpa;

    Student(string name, int age, double gpa) {
        this->name = name;
        this->age = age;
        this->gpa = gpa;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << ", GPA: " << gpa << endl;
    }
};

void printStudent(Student s) {
    cout << "[By Value] Name: " << s.name << endl;
}

void changeGPA(Student* s) {
    s->gpa = 4.0;
}

int main() {
    Student* s = new Student("Dat", 21, 3.7);

    printStudent(*s);       // truyền bản sao
    changeGPA(s);           // truyền con trỏ
    s->display();           // in thông tin sau khi thay đổi

    delete s;
    return 0;
}
