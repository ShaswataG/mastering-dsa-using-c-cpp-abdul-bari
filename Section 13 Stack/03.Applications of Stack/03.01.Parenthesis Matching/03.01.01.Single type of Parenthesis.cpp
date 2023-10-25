using namespace std;
#include<iostream>

template<class T>
class Node {
    public:
        T data;
        Node* next;
};

template<class T>
class Stack {
    private:
        Node<T>* top;
    public:
        Stack();
        void Push(int x);
        T Pop();
        void Peek(int);
        void Display();
        int StackTop();
        int isFull();
        int isEmpty();
};

template<class T>
Stack<T>::Stack() {
    top = NULL;
}

template<class T>
void Stack<T>::Push(int x) {
    Node<T>* t = new Node<T>;
    if (!t) {
        cout << "Stack overflow!" << endl;
        delete t;
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

template<class T>
T Stack<T>::Pop() {
    if (!top) return -1;
    else {
        Node<T>* p = top;
        int x = p->data;
        top = top->next;
        delete p;
        return x;
    }
}

template<class T>
void Stack<T>::Peek(int pos) {
    if (!top) {
        cout << "Stack underflow!" << endl;
        return;
    }
    Node<T>* p = top;
    for (int i = 0; p && i < pos - 1; i++)
        p = p->next;
    if (p) cout << "Element at position " << pos << " is " << p->data << endl;
    else cout << "Invalid position!" << endl;
}

template<class T>
void Stack<T>::Display() {
    if (top) {
        Node<T>* p = top;
        cout << "Elements are : ";
        while(p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    } else
        cout << "Stack underflow!" << endl;
}

template<class T>
int Stack<T>::StackTop() {
    if (!top) return -1;
    return top->data;
}

template<class T>
int Stack<T>::isFull() {
    Node<T>* t = new Node<T>;
    int x = t ? 0 : 1;
    delete t;
    return x;
}

template<class T>
int Stack<T>::isEmpty() {
    return top ? 0 : 1;
}

int isBalance(char* exp) {
    Stack <char> st;
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(')
            st.Push('(');
        else if (exp[i] == ')')
        {   
            if (st.isEmpty() == 1) return 0;
            st.Pop();
        }
    }
    if (st.isEmpty() == 1) return 1;
    else return 0;
}

int main() {
    char a[] = "((A+B)*(c/d))";
    char b[] = "((A+B)*c/d))";
    char c[] = "((A+B*(c/d))";
    cout << isBalance(a) << endl;
    cout << isBalance(b) << endl;
    cout << isBalance(c) << endl;
}