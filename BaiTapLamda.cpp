#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Student {
    std::string name;
    int score;
};

int main() {
    std::vector<Student> students;

    // Nhập danh sách sinh viên
    int n;
    std::cout << "Nhap so sinh vien: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        Student s;
        std::cout << "Nhap ten sinh vien thu " << i + 1 << ": ";
        std::cin >> s.name;
        std::cout << "Nhap diem: ";
        std::cin >> s.score;
        students.push_back(s);
    }

    // Sắp xếp giảm dần theo điểm
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.score > b.score; // giảm dần
    });


    std::cout << "\nDanh sach sinh vien sau khi sap xep theo diem (giam dan):\n";
    for (const auto& s : students) {
        std::cout << "Ten: " << s.name << ", Diem: " << s.score << "\n";
    }

    return 0;
}
