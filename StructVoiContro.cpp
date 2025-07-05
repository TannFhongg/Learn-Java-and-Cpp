#include <iostream>

using namespace std;

struct Student
{
    string id;
    string name;
    double score;
};
void inputStudent(Student *s)
{

    cout << "Nhap id sinh vien: " << endl;
    cin >> s->id;
    cout << "Nhap ten sinh vien: " << endl;
    cin.ignore();
    getline(cin, s->name);
    cout << "Nhap diem cua sinh vien: " << endl;
    cin >> s->score;
}

void display(Student *s)
{
    cout << "Id: " << s->id << "Name: " << s->name << "Scoore: " << s->score << endl;
}

Student *findTopGPA(Student *student, int n)
{

    /*

students[0] là đối tượng Student đầu tiên (không phải con trỏ).

&students[0] là địa chỉ của đối tượng đó → chính là Student*
    */
    Student *top = &student[0];
/*
top là con trỏ (Student*) trỏ tới sinh viên có GPA cao nhất
mà students[i] là đối tượng, không phải con trỏ.
Nên phải dùng & để lấy địa chỉ của đối tượng đó.
*/
    for (int i = 0; i < n; i++)
    {
        if (student[i].score > top->score)
        {
            top->score = student[i].score;
        }
    }
    return top;
}

int main()
{
    cout << "Nhap so luong sinh vien: " << endl;
    int n;
    cin >> n;

    Student *students = new Student[n]; // students là con trỏ tới phần tử đầu tiên của mảng cấp phát động.

    for (int i = 0; i < n; i++)
    {
        inputStudent(&students[i]);
    }
    cout << "Danh sach sinh vien: " << endl;
    for (int i = 0; i < n; i++)
    {
        display(&students[i]);
    }

    Student *maxValue = findTopGPA(students, n);
    cout << "Sinh vien co diem gpa cao nhat la : " << endl;
    display(maxValue);

    delete[] students;
    return 0;
}