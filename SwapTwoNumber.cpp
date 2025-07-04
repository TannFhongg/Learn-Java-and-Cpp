#include <iostream>
using namespace std;

void swapByValue(int a,int b ) { 
    int temp = a; 
    a =b; 
    b= temp; 
}

void swapByReference(int &a,int &b) {
 int temp = a; 
 a = b; 
 b = temp; 

}
int main() { 
    int a = 10; 
    int b =5; 
    cout << "Swap by Value: " << endl; 
    swapByValue(a,b); 
    cout << "a: "<< a<<" " <<  "b:" << b << endl; 

    cout << "Swap by Reference: " << endl; 
    swapByReference(a,b); 
    cout << "a: "<< a<< " " << "b:" << b << endl; 
    return 0; 
}