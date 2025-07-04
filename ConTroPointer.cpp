/*
Con trỏ được coi là biến với giá trị của nó là địa chỉ của biến khác 
*/

#include <iostream>
using namespace std;

int main()
{

    int a = 42;

    int *p = &a;

    cout << "Dia chi cua a : " << &a << endl;
    cout << "Dia chi ma con tro tro toi:" << p << endl;
    cout << "Gia tri ma con tro tro den: " << *p << endl;

    *p = 100; // thay doi gia tri cua a thong qua con tro

    cout << "Gia tri cua a sau khi thay doi bang con tro: " << a << endl;

    int *arr = new int[5]; // cap phat mang dong

    for (int i = 0; i < 5; ++i)
        arr[i] = i * 2;

    for (int i = 0; i < 5; ++i)
        cout << arr[i] << " ";

    delete[] arr; // giai phong bo nho

    return 0;
}