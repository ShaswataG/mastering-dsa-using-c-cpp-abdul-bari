using namespace std;
#include<iostream>

struct Stack {
    int size;
    int top;
    int* s;
};

void Create(Stack* st) {
    cout << "Enter size : ";
    cin >> st->size;
    st->top = -1;
    st->s = new int[st->size];
}

void Display(Stack st) {
    if (st.top == -1) cout << "Stack underflow." << endl;
    for (int i = st.top; i >= 0; i--) {
        cout << st.s[i] << " ";
    }
    cout << endl;
}

void Push(Stack* st, int x) {
    if (st->top >= st->size-1)
        cout << "Stack overflow." << endl;
    else {
        st->top++;
        st->s[st->top] = x;
    }
}

int Pop(Stack* st) {
    int x = -1;
    if (st->top < 0)
        cout << "Stack underflow." << endl;
    else {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int Peek(Stack st, int pos) { 
    if (pos < 1 || pos > st.top+1) {
        cout << "Invalid position" << endl;
        return -1;
    } else {
        return (st.s[st.top+1-pos]);   
    }
}

int StackTop(Stack st) {
    if (st.top == -1) {
        cout << "Stack underflow." << endl;
        return -1;
    } else {
        return (st.s[st.top]);
    }
}

int isEmpty(Stack st) {
    if (st.top == -1) return 1;
    else return 0;
}

int isFull(Stack st) {
    if (st.top >= st.size-1) return 1;
    else return 0;
}

int main() {
    Stack s;
    Create(&s);
    cout << isEmpty(s) << endl;
    cout << isFull(s) << endl;
    Display(s);
    Push(&s, 2);
    Push(&s, 3);
    Push(&s, 5);
    Push(&s, 7);
    Display(s);
    cout << isEmpty(s) << endl;
    cout << isFull(s) << endl;
    return 0;
}