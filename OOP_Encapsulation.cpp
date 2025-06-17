
// class
// thuoc tinh:attribute
// phuong thuc : behavior ,  method
// object: doi tuong

// Accesmodifier :
//  private : chi truy cap trong cung class , khong the truy cap ben ngoai
// public : tat ca moi noi
// protected : cung class, subclass ke thua
// static : khong khoi tao ,dung chung cho ca class
//friend function,friend class

#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>

class SinhVien {
private:
    static int dem;
    std::string maSV;
    std::string id;
    std::string name;
    std::string birthday;
    double gpa;

    std::string sinhMaSV() {
        return "SV" + std::string(3 - std::to_string(dem).length(), '0') + std::to_string(dem);
    }

public:
    SinhVien() {
        ++dem;
        maSV = sinhMaSV();
    }

    friend void ChuanHoa(SinhVien&);

    // Destructor (hiện không cần làm gì)
    ~SinhVien() {}

    // Hàm nhập thông tin từ người dùng
    void nhap() {
        std::cout << "Nhap id: ";
        std::cin >> id;
        std::cin.ignore();
        std::cout << "Nhap ten: ";
        std::getline(std::cin, name);
        std::cout << "Nhap ngay sinh: ";
        std::cin >> birthday;
        std::cout << "Nhap GPA: ";
        std::cin >> gpa;
    }

    // Hàm in thông tin sinh viên
    void in() const {
        std::cout << maSV << " " << id << " " << name << " " << birthday << " "
                  << std::fixed << std::setprecision(2) << gpa << '\n';
    }

    double getGPA() const {
        return gpa;
    }
};
void ChuanHoa(SinhVien &a) {
    std::string res = "";
    std::stringstream ss(a.name); 
    std::string token; 

    while (ss >> token) {
        res+= toupper(token[0]); 
        for(int i = 1; i < token.length();i++) {
            res+=tolower(token[i]); 
        }
        res+= " "; 
    }
    res.erase (res.length() - 1) ; 
    a.name = res ; 
}
// Khởi tạo biến static
int SinhVien::dem = 0;

// Hàm so sánh GPA giảm dần
bool soSanhGPA(const SinhVien& a, const SinhVien& b) {
    return a.getGPA() > b.getGPA();
}

// Chương trình chính
int main() {
    char tiepTuc = 'y';
    while (tiepTuc == 'y' || tiepTuc == 'Y') {
        int n;
        std::cout << "Nhap so sinh vien: ";
        std::cin >> n;

        std::vector<SinhVien> danhSach;
        for (int i = 0; i < n; ++i) {
            std::cout << "Nhap sinh vien thu " << i + 1 << ":\n";
            SinhVien sv;
            sv.nhap();
            ChuanHoa(sv); 
            danhSach.push_back(sv);
        }

        std::sort(danhSach.begin(), danhSach.end(), soSanhGPA);

        std::cout << "\nDanh sach sinh vien theo GPA giam dan:\n";
        for (const auto& sv : danhSach) {
            sv.in();
        }

        std::cout << "\nBan co muon tiep tuc? (y/n): ";
        std::cin >> tiepTuc;
        std::cin.ignore();
    }

    return 0;
}
