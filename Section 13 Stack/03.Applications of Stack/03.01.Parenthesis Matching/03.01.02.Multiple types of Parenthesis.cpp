using namespace std;
#include<iostream>
#include<string>

struct Stack {
    int size;
    int top;
    char* s;
} * top;

void Create(Stack* st, int l) {
    st->top = -1;
    // cout << "Enter size : ";
    // cin >> st->size;
    st->size = l;
    st->s = new char[st->size];
}

void Push(Stack* st, int x)
{
    if (st->top == st->size - 1)
        cout << "Stack overflow!" << endl;
    else {
        st->top++;
        st->s[st->top] = x;
    }
}

char Pop(Stack* st) {
    if (st->top == -1) {
        cout << "Stack underflow!" << endl;
        return '0';
    } else {
        char x = st->s[st->top];
        top--;
        return x;
    }
}

char StackTop(Stack st) {
    if (st.top == -1) cout << "Stack underflow!" << endl;
    else return st.s[st.top];
}

int isEmpty(Stack st) {
    if (st.top == -1) {
        return 1;
    } else return 0;
}

void Display(Stack st) {
    if (st.top == -1) cout << "Stack underflow!" << endl;
    else {
        for (int i = st.top; i >= 0; i--) {
            cout << st.s[i] << " ";
        }
        cout << endl;
    }
}

int isBalance(string exp) {
    Stack s;
    Create(&s, exp.length());
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            Push(&s, exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if ((StackTop(s) == '(' && exp[i] == ')') || (StackTop(s) == '{' && exp[i] == '}') || (StackTop(s) == '[' && exp[i] == ']'))
                Pop(&s);
            else return 0;
        }
        if (isEmpty(s) == 1) return 1;
        else return 0;
    }
}

int main() {
    Stack s;
    string exp = "[{(a+b)/[c-d]} * {(a*b)/c}]";
    cout << isBalance(exp) << endl;
    return 0;
}