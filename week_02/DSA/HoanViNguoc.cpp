#include <bits/stdc++.h>

// Hàm prev_permutation cho mảng số nguyên
template<typename T>
bool prev_permutation(T* first, T* last) {
    if (first == last) return false;
    T* i = last;
    if (first == --i) return false;
    while (true) {
        T* i1 = i;
        if (*--i > *i1) {
            T* j = last;
            while (!(*--j < *i)) {}
            std::swap(*i, *j);
            std::reverse(i1, last);
            return true;
        }
        if (i == first) {
            std::reverse(first, last);
            return false;
        }
    }
}

int n, a[1005];
int main()
{
    std::cout << "Nhap so luong test:" << std::endl;
    int t;
    std::cin >> t;
    while (t--)
    {
        /* code */
        std::cin >> n;
        int l = 1;
        for (int i = 0; i < n; i++)
        {
            a[i] = i + 1;
            l *= i + 1;
        }

        while (l--)
        {
            prev_permutation(a, a + n);
            for (int i = 0; i < n; i++)
            {
                std::cout << a[i];
                
            }
            std::cout <<" "; 
        }
        std::cout << std::endl;
    }
}
