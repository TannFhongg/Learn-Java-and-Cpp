#include <bits/stdc++.h>
using namespace std;

class Shape {
public:
    virtual void drawing() = 0;
    virtual double area() = 0;
};

class DoubleDShape : public Shape {
public:
    virtual double perimeter() = 0;
};

class Rectangle : public DoubleDShape {
public:
    double w, h;
    Rectangle(double w, double h) : w(w), h(h) {}

    double area() override {
        return w * h;
    }

    double perimeter() override {
        return (w + h) * 2;
    }

    void drawing() override {
        cout << "The rectangle is drawing" << endl;
    }
};

class Square : public DoubleDShape {
public:
    double a;
    Square(double a) : a(a) {}

    double area() override {
        return a * a;
    }

    double perimeter() override {
        return a * 4;
    }

    void drawing() override {
        cout << "The square is drawing" << endl;
    }
};

int main() {
    DoubleDShape* rec = new Rectangle(4, 5);
    DoubleDShape* sq = new Square(3);

    rec->drawing();
    cout << "Area: " << rec->area() << endl;
    cout << "Perimeter: " << rec->perimeter() << endl;

    sq->drawing();
    cout << "Area: " << sq->area() << endl;
    cout << "Perimeter: " << sq->perimeter() << endl;

    delete rec;
    delete sq;

    return 0;
}
