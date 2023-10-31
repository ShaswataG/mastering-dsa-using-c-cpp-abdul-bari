using namespace std;
#include<iostream>

template<class T>
class Node {
    T data;
    Node<T>* next;
};

template<class T>
class Stack {
    public:
        Node<T>* top;
        Node<T>* s;
    public:
        Stack();
        void Push(T);
        T Pop();
        void Display();
        T StackTop();
        int isEmpty();
        int isFull(); 
};

template<class T>
Stack<T>::Stack() {
    top = NULL;
};

template<class T>
void Stack<T>::Push(T x) {
    Node<T>* t = new Node<T>;
    if (!t) {
        cout << "Stack is full." << endl;
        delete t;
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

template<class T>
T Stack<T>::Pop() {
    int x = -1;
    if (!top) {
        cout << "Stack is empty." << endl;
        x = -1;
    } else {
        x = top->data;
        Node<T>* p = top;
        top = top->next;
        delete p;
    }
    return x;
}

template<class T>
void Stack<T>::Display() {
    if (!top) cout << "Stack is empty." << endl;
    else {
        Node<T>* p = top;
        cout << "Elements are : ";
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

template<class T>
T Stack<T>::StackTop() {
    if (!top) {
        cout << "Stack is empty." << endl;
        return -1;
    } else {
        return top->data;
    }
}

template<class T>
int Stack<T>::isEmpty() {
    if (!top) return 1;
    else return 0;
}

template<class T>
int Stack<T>::isFull() {
    Node<T>* t = new Node<T>;
    if (!t) return 1;
    else return 0;
}

template<class T>
class Queue {
    private:
        Stack<T> s1, s2;
    public:
        Queue();
        void Enqueue(T);
        T Dequeue();
};

template<class T>
Queue<T>::Queue() {
}

template<class T>
void Queue<T>::Enqueue(T x) {
    s1.Push(x);
}

template<class T>
T Queue<T>::Dequeue() {
    int x = -1;
    if (!s2.isEmpty()) return s2.Pop();
    else {
        if (s1.isEmpty()) {
            cout << "Queue is empty." << endl;
            return x;
        } else {
            while (!s1.isEmpty()) {
                s2.Push(s1.Pop);
            }
        }
    }
    return s2.Pop();
}

int main() {
    int a[] = {6, 3, 9, 5, 4, 2, 8, 12, 20};
    Queue<int> q;
    for (int i = 0; i < 9; i++)
    {
        q.Enqueue(a[i]);
    }
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
    return 0;
}