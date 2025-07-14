#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};
typedef Node* node;

node makeNode(int x) {
    node temp = new Node();
    temp->data = x;
    temp->next = NULL;
    return temp;
}

bool empty(node a) {
    return a == nullptr;
}

int size(node a) {
    int count = 0;  // 💡 thêm khởi tạo
    while (a != nullptr) {
        count++;
        a = a->next;
    }
    return count;
}

void insertFirst(node &a, int x) {
    node temp = makeNode(x);
    temp->next = a;
    a = temp;
}

void insertLast(node &a, int x) {
    node temp = makeNode(x);
    if (a == nullptr) {
        a = temp;
    } else {
        node p = a;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = temp;
    }
}

void insertMid(node &a, int x, int pos) {
    int n = size(a);
    if (pos < 1 || pos > n + 1) {
        cout << "Vi tri chen khong hop le" << endl;
        return;
    }
    if (pos == 1) {
        insertFirst(a, x);
        return;
    } else if (pos == n + 1) {
        insertLast(a, x);
        return;
    }

    node p = a;
    for (int i = 1; i < pos - 1; i++) {
        p = p->next;
    }

    node temp = makeNode(x);
    temp->next = p->next;
    p->next = temp;
}
void deleteFirst(node &a) {
    if(a == nullptr) return; 
    a = a -> next;
}
void deleteLast(node &a) {
    if (a == nullptr) return;  // danh sách rỗng

    if (a->next == nullptr) {  // chỉ có 1 phần tử
        delete a;
        a = nullptr;
        return;
    }

    node prev = nullptr;
    node curr = a;

    while (curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
    }

    // curr là node cuối, prev là node kế cuối
    delete curr;
    prev->next = nullptr;
}
void deleteMid(node &a, int pos) {
    if (a == nullptr || pos <= 0 || pos > size(a)) return;

    if (pos == 1) {
        node temp = a;
        a = a->next;
        delete temp;
        return;
    }

    node prev = nullptr, curr = a;
    for (int i = 1; i < pos; ++i) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    delete curr;
}

void in(node a) { 
    while (a != nullptr)
    {
        cout << a -> data << " "; 
        a = a -> next;
    }
    
}
int main() {
    node head = nullptr;
    int choice, x, pos;

    do {
        cout << "\n====== MENU ======\n";
        cout << "1. Chen dau danh sach\n";
        cout << "2. Chen cuoi danh sach\n";
        cout << "3. Chen giua danh sach\n";
        cout << "4. Xoa dau danh sach\n";
        cout << "5. Xoa cuoi danh sach\n";
        cout << "6. Xoa o vi tri\n";
        cout << "7. In danh sach\n";
        cout << "8. So luong phan tu\n";
        cout << "0. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap gia tri can chen dau: ";
                cin >> x;
                insertFirst(head, x);
                break;
            case 2:
                cout << "Nhap gia tri can chen cuoi: ";
                cin >> x;
                insertLast(head, x);
                break;
            case 3:
                cout << "Nhap gia tri va vi tri can chen (x pos): ";
                cin >> x >> pos;
                insertMid(head, x, pos);
                break;
            case 4:
                deleteFirst(head);
                cout << "Da xoa phan tu dau." << endl;
                break;
            case 5:
                deleteLast(head);
                cout << "Da xoa phan tu cuoi." << endl;
                break;
            case 6:
                cout << "Nhap vi tri can xoa: ";
                cin >> pos;
                deleteMid(head, pos);
                break;
            case 7:
                cout << "Danh sach hien tai: ";
                in(head);
                cout << endl;
                break;
            case 8:
                cout << "So luong node: " << size(head) << endl;
                break;
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long thu lai.\n";
        }

    } while (choice != 0);

    return 0;
}
