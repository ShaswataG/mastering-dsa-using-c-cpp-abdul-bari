using namespace std;
#include<iostream>

// template<class T>

class Stack {
    public:
        int size;
        int top;
        int* s;
        Stack();
        void Create();
        void Display();
        void Push(int);
        int Pop();
        int Peek(int);
        int StackTop();
        int isEmpty();
        int isFull();
};

Stack::Stack() {
}

void Stack::Create() {
    cout << "Enter size of stack : ";
    cin >> size;
    top = -1;
    s = new int[size];
}

void Stack::Display() {
    if (top == -1)
        cout << "Stack underflow!" << endl;
    else {
        for (int i = top; i >= 0; i++) {
            cout << s[i] << " ";
        }
        cout << endl;
    }
}

void Stack::Push(int x) {
    if (top == size-1)
        cout << "Stack overflow!" << endl;
    else {
        top++;
        s[top] = x;
    }
}

int Stack::Pop() {
    int x = -1;
    if (top == -1) {
        cout << "Stack underflow!" << endl;
    } else {
        x = s[top];
        top--;
    }
    return x;
}

int Stack::Peek(int pos) {
    if (pos < 1 || pos > size) {
        cout << "Invalid position!" << endl;
        return -1;
    } else {
        return s[top+1-pos];
    }
}

int Stack::StackTop() {
    if(top == -1) {
        cout << "Stack underflow!" << endl;
        return -1;
    } else {
        return s[top];
    }
}

int Stack::isEmpty() {
    if (top == -1) return 1;
    else return 0;
}

int Stack::isFull() {
    if (top == size-1) return 1;
    else return 0;
}

int main() {
    Stack st;
    int choice;
    while (true) {
        cout << "Press 1 to create." << endl;
        cout << "Press 2 to display." << endl;
        cout << "Press 3 to push." << endl;
        cout << "Press 4 to pop." << endl;
        cout << "Press 5 to peek." << endl;
        cout << "Press 6 to view top element." << endl;
        cout << "Press 7 to check if stack is empty." << endl;
        cout << "Press 8 to check if stack is full." << endl;
        cout << "Press 9 to exit." << endl;
        cin >> choice;
        switch (choice) {
            case 1 : {
                st.Create();
            }
            break;
            case 2 : {
                st.Display();
            }
            break;
            case 3 : {
                int a;
                cout << "Enter element you want to push : ";
                cin >> a;
                st.Push(a);
            }
            break;
            case 4 : {
                st.Pop();
            }
            break;
            case 5 : {
                int a;
                cout << "Enter position you want to view element at : ";
                cin >> a;
                if (a < 1 || a > st.size)
                    st.Peek(a);
                else
                    cout << "Position " << a << " has the element " << st.Peek(a) << endl;
            }
            break;
            case 6 : {
                if (st.top == -1)
                    st.StackTop();
                else
                    cout << "Top element is " << st.StackTop() << endl;
            }
            break;
            case 7 : {
                if (st.isEmpty() == 1)
                    cout << "Stack is empty." << endl;
                else
                    cout << "Stack is not empty." << endl;
            }
            break;
            case 8 : {
                if (st.isFull() == 1)
                    cout << "Stack is full." << endl;
                else
                    cout << "Stack is not full." << endl;
            }
            break;
            default : exit(0);
            break;
        }
    }
    return 0;
}