using namespace std;
#include<iostream>

struct Node {
    int data;
    struct Node* next;
} * top = NULL;

void Push(int x) {
/*
TC = O(1) (always) similar to inserting a node at index 0 or before first/top node
*/
    Node* t = new Node;
    if (t == NULL)
        cout << "Stack overflow!" << endl;
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Pop() {
/*
TC = O(1) (always)
*/
    Node* p;
    int x = -1;
    if (top) {
        p = top;
        x = top->data;
        top = top->next;
        delete p;
        cout << "Element popped is " << x << endl;
    } else {
        cout << "Stack underflow!" << endl;
    }
    return x;
}

int Peek(int pos) {
    Node* p = top;
/*
    for (int i = 0; i < pos - 1; i++) {
        if (p->next)
            p = p->next;
        else {
            cout << "Invalid position!" << endl;
            return -1;
        }
    }
    return p->data;
*/
    for (int i = 0; p && i < pos - 1; i++)
        p = p->next;
    if (p) return p->data;
    else return -1;
}

void Display() {
    Node* p = top;
    if (p) {
        cout << "Elements are : ";
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    } else {
        cout << "Stack underflow!" << endl;
    }
}

int StackTop() {
    if (top)
        return top->data;
    else
        return -1;
}

int isFull() {
    Node* t = new Node;
    int r = t ? 0 : 1;
    delete t;
    return r;
}
 
int isEmpty() {
    if (!top) return 1;
    else return 0;
}

int main() {
    int choice;
    while (1) {
        cout << endl;
        cout << "Press 1 to push." << endl;
        cout << "Press 2 to pop." << endl;
        cout << "Press 3 to peek." << endl;
        cout << "Press 4 to display." << endl;
        cout << "Press 5 to view top element." << endl;
        cout << "Press 6 to check if stack is full." << endl;
        cout << "Press 7 to check if stack is empty." << endl;
        cout << "Press 8 to exit." << endl;
        cin >> choice;
        switch(choice) {
            case 1 :
                int a;
                cout << "Enter element you want to push : ";
                cin >> a;
                Push(a);
                break;
            case 2 :
                Pop();
                break;
            case 3 :
                int b;
                cout << "Enter position you want to peek at : ";
                cin >> b;
                if (Peek(b) == -1) cout << "Invalid position." << endl;
                else cout << "Element at position " << b << " is " << Peek(b) << endl;
                break;
            case 4 :
                Display();
                break;
            case 5 :
                if (StackTop() == -1)
                    cout << "Stack underflow!" << endl;
                else
                    cout << "Element at top position is " << StackTop() << endl;
                break;
            case 6 :
                if (isFull() == 1) cout << "Stack is full." << endl;
                else cout << "Stack is not full." << endl;
                break;
            case 7:
                if (isEmpty() == 1) cout << "Stack is empty." << endl;
                else cout << "Stack is not empty." << endl;
                break;
            default :
                exit(0);
                break; 
        }
    }
    return 0;
}