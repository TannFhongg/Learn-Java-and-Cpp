#include <bits/stdc++.h>

using namespace std;
class Person
{
private:
    string name;
    string address;

public:
    string getName()
    {
        return name;
    }
    string getAddress()
    {
        return address;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setAddress(string address)
    {
        this->address = address;
    }
    void in() {
        cout << name << " " << address << " "; 
    }

    Person(string name,string address) {
        this -> name = name; 
        this -> address = address; 
    }
};

class Student : public Person
{
private:
    double gpa;

public:
    double getGPA()
    {
        return gpa;
    }
    void setGPA(double gpa)
    {
        this->gpa = gpa;
    }
    void in() { // function overriding
        Person::in(); 
        cout << gpa << fixed << setprecision(2) << endl; 
    }
    Student(string name,string address, double gpa) : Person( name, address) {
        this -> gpa = gpa; 
    }
};

int main()
{

    Student s("Tuanvv","QuangBinh",3.50);
    // s.setName("Tuanvv");
    // s.setAddress("QuangBinh");
    // s.setGPA(3.0);
    s.in(); 
   // s.Person::in(); 

}