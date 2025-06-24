#include <bits/stdc++.h>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {}
    Person() {}

    string getName() const { return name; }
    void setName(string name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    int getAge() const { return age; }
};

class Student : public Person {
private:
    string id;
    double gpa;

public:
    Student(string id, string name, int age, double gpa)
        : Person(name, age), id(id), gpa(gpa) {}
    Student() {}

    string getId() const { return id; }
    void setId(string id) { this->id = id; }
    double getGpa() const { return gpa; }
    void setGpa(double gpa) { this->gpa = gpa; }

    virtual void display() const {
        cout << id << " " << getName() << " " << getAge() << " " << gpa << endl;
    }

    virtual ~Student() {}
};

class HocSinhHocBong : public Student {
private:
    double tienThuong;

public:
    HocSinhHocBong(string id, string name, int age, double gpa, double tienThuong)
        : Student(id, name, age, gpa), tienThuong(tienThuong) {}

    void setTienThuong(double tienThuong) { this->tienThuong = tienThuong; }
    double getTienThuong() const { return tienThuong; }

    bool duocHocBong() const {
        return getGpa() > 3.5;
    }

    void display() const override {
        Student::display();
        if (duocHocBong()) {
            cout << " --> Duoc hoc bong: " << tienThuong << " VND\n";
        } else {
            cout << " --> Khong duoc hoc bong\n";
        }
    }
};

class AbstractManager {
public:
    virtual void addStudent(Student* s) = 0;
    virtual void displayAll() const = 0;
    virtual ~AbstractManager() {}
};

class ManagerStudent : public AbstractManager {
private:
    list<Student*> ls;

public:
    void addStudent(Student* s) override {
        ls.push_back(s);
    }

    void displayAll() const override {
        for (Student* s : ls) {
            s->display();
        }
    }

    ~ManagerStudent() {
        for (Student* s : ls) {
            delete s;
        }
    }
};

int main() {
    ManagerStudent st;
    int n;

    cout << "Nhap so sinh vien: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string id, name;
        int age;
        double gpa;

        cout << "Nhap ID: ";
        getline(cin, id);

        cout << "Nhap ten: ";
        getline(cin, name);

        cout << "Nhap tuoi: ";
        cin >> age;

        cout << "Nhap GPA: ";
        cin >> gpa;

        double thuong = 0;
        if (gpa > 3.5) {
            cout << "Nhap so tien thuong: ";
            cin >> thuong;
            cin.ignore();
            st.addStudent(new HocSinhHocBong(id, name, age, gpa, thuong));
        } else {
            cin.ignore();
            st.addStudent(new Student(id, name, age, gpa));
        }
    }

    cout << "Student of List: ";
    st.displayAll();
    return 0;
}
