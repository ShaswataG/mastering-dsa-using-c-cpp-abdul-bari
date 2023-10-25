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
        Node<T>* top = NULL;
    public:
        Stack();
        void Push(T);
        void Pop();
        int isEmpty();
        T StackTop();
};

template<class T>
Stack<T>::Stack() {
    top = NULL;
}

template<class T>
void Stack<T>::Push(T x) {
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
void Stack<T>::Pop() {
    if (!top) cout << "Stack underflow!" << endl;
    else {
        Node<T>* t = top;
        top = top->next;
        T x = t->data;
        delete t;
        cout << "Popped element is " << x << endl;
    }
}

template<class T>
T Stack<T>::StackTop() {
    if (!top) {
        cout << "Stack underflow!" << endl;
        return 0;
    } else {
        return top->data;
    }
}

template<class T>
int Stack<T>::isEmpty() {
    if (!top) return 1;
    else return 0;
}

int precedence(char c) {
    if(c == '-' || c == '+') return 1;
    else if (c == '*' || c == '/') return 2;
    else return 3;
}

int length(char* s) {
    int len = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}

int isOperand(char x) {
    if (x == '*' || x == '/' || x == '+' || x == '-') return 0;
    return 1;
}

char* convert1(char* infix) {
    Stack<char> s;
    char* postfix = new char[length(infix)+1];
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        if ((precedence(infix[i]) > precedence(s.StackTop())) || s.StackTop() == '\0')
        {
            s.Push(infix[i]);
        }
        else
        {
            while (precedence(infix[i]) <= s.StackTop()) {
                postfix[j] = s.StackTop();
                j++;
                s.Pop();
            }
            s.Push(infix[i]);
        }
    }
    while (!s.isEmpty()) {
        postfix[j++] = s.StackTop();
        s.Pop();
    }
    postfix[j] = '\0';
    return postfix;
}

void convert2(char* infix) {
    Stack<char> s;
    char postfix[length(infix)+1];
    int j = 0;
    for (int i = 0; infix[i] !='\0'; i++)
    {
        if (isOperand(infix[i]) == 1)
        {
            postfix[j] = infix[i];
            j++;
        } else
        {
            if ((precedence(infix[i]) > precedence(s.StackTop())) || s.StackTop() == '\0')
            {
                s.Push(infix[i]);
            }
            else
            {
                while (precedence(infix[i]) <= s.StackTop()) {
                    postfix[j] = s.StackTop();
                    j++;
                    s.Pop();
                }
                s.Push(infix[i]);
            }
        }
    }
    while (!s.isEmpty())
    {
        postfix[j++] = s.StackTop();
        s.Pop();
    }
    postfix[j] = '\0';
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        cout << postfix[i];
    }
    cout << endl;
}

int main() {
    char exp[] = "a+b*c-d/e\0";
    // cout << convert1(exp) <<endl;   // wrong result
    convert2(exp);
    return 0;
}