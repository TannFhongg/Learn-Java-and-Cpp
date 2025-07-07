#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20;

    // [=] bắt tất cả theo GIÁ TRỊ (copy)
    auto f1 = [=]() {
        cout << "f1: a + b = " << a + b << endl;
        // a = 5; ❌ không được gán vì là copy
    };

    // [&] bắt tất cả theo THAM CHIẾU
    auto f2 = [&]() {
        a += 1;
        b += 2;
        cout << "f2: a = " << a << ", b = " << b << endl;
    };

    // [a] bắt chỉ a theo giá trị
    auto f3 = [a]() {
        cout << "f3: a = " << a << endl;
        // a = 100; ❌ không được vì là copy
    };

    // [&b] bắt chỉ b theo tham chiếu
    auto f4 = [&b]() {
        b += 5;
        cout << "f4: b = " << b << endl;
    };

    // [=, &b] bắt tất cả theo giá trị, b theo tham chiếu
    auto f5 = [=, &b]() {
        // cout << a; ✅ OK (copy)
        b += 10;     // ✅ OK (tham chiếu)
    };

    f1();  // In: a + b = 30
    f2();  // Cập nhật a, b theo tham chiếu
    f3();  // a giữ nguyên giá trị cũ
    f4();  // b tăng tiếp
    f5();  // b += 10

    cout << "Cuoi cung: a = " << a << ", b = " << b << endl;
    return 0;
}
