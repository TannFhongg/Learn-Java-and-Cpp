#include <iostream>
#include <memory> 
/*
unique_ptr chi co 1 chu so huu duy nhat
khong cho copy chi co the move owner
*/

/*
share_ptr cho phep nhieu con tro so huu 1 doi tuong 
tu dong giai phong khi ref count = 0 

*/

/*
weak_ptr de tranh vong tham chieu(circular reference) giua cac share_ptr 
khong tang ref count
*/
using namespace std; 
class A {
    public: 
    A() { 
        cout << "Constructor A" << endl; 
    }
    ~A() { 
        cout << "Destructor A " << endl; 
    }
    void say() { 
        cout << "This is class A" << endl ;
    }
};

class B {
    public: 
    B() { 
        cout << "Constructor B" << endl; 
    }
    ~B() { 
        cout << "Destructor B" << endl; 
    }
    void say() { 
        cout << "This is class B" << endl ;
    }
};
class C {
    public: 
    weak_ptr<C> other; 
    C() { 
        cout << "Constructor C" << endl; 
    }
    ~C() { 
        cout << "Destructor C" << endl; 
    }
    void say() { 
        cout << "This is class C" << endl ;
    }
};



int main() {
    cout << "UNIQUE_PTR" <<endl; 
    unique_ptr<A> ptr =make_unique<A>();

    ptr -> say (); 
    unique_ptr<A> ptr2  = move(ptr); 
    ptr2 -> say(); 
    cout << "---------------------------------------------------------------------------" << endl; 
     cout << " SHARE_PTR" <<endl; 
// share_ptr 
shared_ptr<B> p1 = make_shared<B>(); 
p1 -> say(); 
shared_ptr<B> p2 = p1; 
p2 -> say(); 
cout << "Use count: " << p1.use_count() << "\n"; // 2

cout << "_---------------------------------------------------------------------------------" << endl; 
cout << "WEAK_PTR" << endl; 
//weak_ptr
shared_ptr<C> a1 = make_shared<C>(); 
shared_ptr<C> a2 = make_shared<C>(); 
a1 -> other = a1; 
a2 -> other = a2; 

cout << "User counnt" << a1.use_count() << endl; 


}