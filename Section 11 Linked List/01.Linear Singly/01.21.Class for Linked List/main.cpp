using namespace std;
#include<iostream>

class Node {
    public:
        int data;
        Node* next;
};

class LinkedList {
    private:
        Node* first;
    public:
        LinkedList() {first = NULL;}
        LinkedList(int A[], int n);
        ~LinkedList();

        void Display();
        void Insert(int index, int x);
        int Delete(int index);
        int Length();
};

LinkedList::LinkedList(int A[], int n) {
    Node* temp, * last;
    first = new Node;
    first->data = A[0];
    first->next = NULL; 
    last = first;
    for (int i = 1; i < n; i++) {
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

LinkedList::~LinkedList() {
    Node* p = first;
    while(first) {
        first = first->next;
        delete p;
        p = first;
    }
}
 
void LinkedList::Display() {
    Node* p = first;
    while(p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int LinkedList::Length() {
    Node* p = first;
    int len = 0;
    while (p) {
        len++;
        p = p->next;
    }
    return len;
}

void LinkedList::Insert(int index, int x) {
    Node* t, * p = first;
    if (index < 0 || index > Length()) return;
    t = new Node;
    t->data = x;
    t->next = NULL;
    if (index == 0) {
        // t->next = first;
        first = t;
    } else {
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int LinkedList::Delete(int index) {
    Node * p, * q = NULL;
    int x = -1;
    if (index < 1 || index > Length()) return -1;
    if (index = 1) {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    } else {
        p = first;
        for(int i = 0; i < index - 1; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

int main() {
    int choice;
    int pos;
    int value;
    LinkedList l;
    while(true) {
        cout << "Press 1 to insert." << endl;
        cout << "Press 2 to display." << endl;
        cout << "Press 3 to delete." << endl;
        cout << "Press 4 for length." << endl;
        cout << "Press 5 to exit." << endl;
        cin >> choice;
        switch(choice) {
            case 1 : {
                cout << "Enter index you want to insert at : ";
                cin >> pos;
                cout << "Enter value you want to insert : ";
                cin >> value;
                l.Insert(pos, value);
            }
            break;
            case 2 : {
                l.Display();
            }
            break;
            case 3 : {
                cout << "Enter index you want to delete at : ";
                cin >> pos;
                cout << "Node at index " << l.Delete(pos) << " deleted successfully." << endl;
            }
            break;
            case 4 : cout << "Length of the Linked List is " << l.Length() << endl;
            break;
            default : exit(0);
            break;
        }
    }
    // int a[] = {2, 3, 5, 7 , 9};
    // LinkedList l(a, 5);
    // l.Display();
    // l.Delete(2);
    // l.Display();
    // l.Insert(3, 42);
    // l.Display();
    return 0;
}