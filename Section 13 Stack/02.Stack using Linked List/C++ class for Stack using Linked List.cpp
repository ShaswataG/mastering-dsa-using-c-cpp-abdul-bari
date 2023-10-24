using namespace std;
#include<iostream>

class Node {
    public:
        int data;
        Node* next;
};

class Stack {
    private:
        Node* top;
    public:
        Stack();
        void Push(int x);
        int Pop();
        void Peek(int);
        void Display();
        int StackTop();
        int isFull();
        int isEmpty();
};

Stack::Stack() {
    top = NULL;
}

void Stack::Push(int x) {
    Node* t = new Node;
    if (!t) {
        cout << "Stack overflow!" << endl;
        delete t;
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::Pop() {
    if (!top) return -1;
    else {
        Node* p = top;
        int x = p->data;
        top = top->next;
        delete p;
        return x;
    }
}

void Stack::Peek(int pos) {
    if (!top) {
        cout << "Stack underflow!" << endl;
        return;
    }
    Node* p = top;
    for (int i = 0; p && i < pos - 1; i++)
        p = p->next;
    if (p) cout << "Element at position " << pos << " is " << p->data << endl;
    else cout << "Invalid position!" << endl;
}

void Stack::Display() {
    if (top) {
        Node* p = top;
        cout << "Elements are : ";
        while(p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    } else
        cout << "Stack underflow!" << endl;
}

int Stack::StackTop() {
    if (!top) return -1;
    return top->data;
}

int Stack::isFull() {
    Node* t = new Node;
    int x = t ? 0 : 1;
    delete t;
    return x;
}

int Stack::isEmpty() {
    return top ? 0 : 1;
}

int main() {
    int choice, a, c, b, d;
    Stack st;
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
        switch (choice)
        {
        case 1:
            a;
            cout << "Enter element you want to push : ";
            cin >> a;
            st.Push(a);
            break;
        case 2:
            c = st.Pop();
            if (c == -1) cout << "Stack Underflow!" << endl;
            else cout << "Element popped is " << c << endl;
            break;
        case 3:
            b;
            cout << "Enter element you want to peek at : ";
            cin >> b;
            st.Peek(b);
            break;
        case 4:
            st.Display();
            break;
        case 5:
            d = st.StackTop();
            if (d == -1) cout << "Stack underflow!" << endl;
            else cout << "Element at top position is " << d << endl; 
            break;
        case 6:
            if (st.isFull() == 1) cout << "Stack is full." << endl;
            else cout << "Stack is not full." << endl;
            break;
        case 7:
            if (st.isEmpty() == 1) cout << "Stack is empty." << endl;
            else cout << "Stack is not empty." << endl;
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}