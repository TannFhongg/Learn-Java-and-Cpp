// Đa hình là khả năng của một đối tượng có thể có nhiều hình thức
//cùng một lời gọi hàm 
//nhưng thực hiện hành vi khác nhau tùy kiểu đối tượng.

//Compile-time	Nạp chồng hàm (function overloading), toán tử 
//Run-time	Hàm ảo (virtual function), ghi đè (overriding)


#include <bits/stdc++.h> 
using namespace std; 
//Đa hình tại thời điểm biên dịch 
class Print {
public:
    void show(int x) {
        cout << "Số nguyên: " << x << endl;
    }
    void show(string s) {
        cout << "Chuỗi: " << s << endl;
    }
};


// Đa hình tại thời điểm chạy
class Animal {
    public: 
   virtual void sound() {
        cout << "Animal make sound \n"; 
    }

}; 
class Dog : public Animal {
    public: 
    void sound() override {
        cout << "Dog makeSound gougou! \n"; 
    }
};
void makeSound(Animal *a) {
    a -> sound();
}

//Pure virtual & Lớp trừu tượng (abstract class) 
class Shape {
public:
    virtual void draw() = 0; // pure virtual → abstract class
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle\n";
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing Square\n";
    }
};

int main() {
Animal* a = new Dog(); 
makeSound(a); // a ->sound(); 


    Shape* s1 = new Circle();
    Shape* s2 = new Square();

    s1->draw(); // Drawing Circle
    s2->draw(); // Drawing Square
}