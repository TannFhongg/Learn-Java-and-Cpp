#include <iostream> 

using namespace std;
void passByValue(int a)
{
    a = 10;
}

void passByReference(int &a)
{
    a = 10;
}
int main()
{
    int a = 5;
    passByValue(a);
    cout << "a after pass by value: " << a << endl;

    passByReference(a);
    cout << "a pass by reference: " << a << endl;
    return 0;
}