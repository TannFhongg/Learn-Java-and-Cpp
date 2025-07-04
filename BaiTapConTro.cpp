#include <iostream>
using namespace std;


void nhapMang(int *arr, int n) {
    cout << "Nhap " << n << " phan tu:\n";
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);
    }
}

void inMang(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}


void sapXepTangDan(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}


void sapXepGiamDan(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(arr + j) < *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int timMax(int *arr, int n) {
    int max = *arr;
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}


int timMin(int *arr, int n) {
    int min = *arr;
    for (int i = 1; i < n; i++) {
        if (*(arr + i) < min) {
            min = *(arr + i);
        }
    }
    return min;
}

int timMin2(int *arr,int n) {
    int min = *arr; 
    int *end = arr + n; 
    arr++; 
    for(;arr < end;arr++) { 
        if(*arr < min) {
            min = *arr; 
        }
    }
    return min; 
}

double tinhTrungBinh(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(arr + i);
    }
    return static_cast<double>(sum) / n;
}

int main() {
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    int *arr = new int[n];

    nhapMang(arr, n);

    cout << "\nMang da nhap: ";
    inMang(arr, n);

    sapXepTangDan(arr, n);
    cout << "Mang sau khi sap xep tang dan: ";
    inMang(arr, n);

    sapXepGiamDan(arr, n);
    cout << "Mang sau khi sap xep giam dan: ";
    inMang(arr, n);

    cout << "So lon nhat: " << timMax(arr, n) << endl;
    cout << "So nho nhat: " << timMin(arr, n) << endl;
    cout << "Trung binh cong: " << tinhTrungBinh(arr, n) << endl;

    delete[] arr;
    return 0;
}
