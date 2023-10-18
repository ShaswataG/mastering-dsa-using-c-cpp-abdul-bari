using namespace std;
#include<iostream>

struct Node {
    int data;
    struct Node* next;
}* first;

void create(int base, int power) {
    struct Node* t, * last;
    first = new Node;
    first->data = 1;
    first->next = NULL;
    last = first;
    for (int i = 1; i <= power; i++) {
        t = new Node;
        t->data = last->data*base;
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display1(struct Node* p) {
/*
TC = O(n)
SC = O(n)
*/
    if (p != NULL) {
        cout << p->data << " ";
        Display1(p->next);
    }
    cout << endl;
}

void Display2(struct Node* p) {
/*
TC = O(n)
SC = O(n)
*/
    if (p != NULL) {
        Display2(p->next);
        cout << p->data << " ";
    }
}

int main() {
    create(3, 4);
    Display1(first);
    Display2(first);
    cout << endl;
    return 0;
}