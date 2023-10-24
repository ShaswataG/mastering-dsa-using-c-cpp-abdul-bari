using namespace std;
#include<iostream>

struct Node {
    int data;
    struct Node* next;
} * first;

void Create(int a[], int n) {
    Node* t, * last;
    first = new Node;
    first->data = a[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(struct Node* p) {
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int Middle1(struct Node* p) {
/*
my trial
*/
    Node* q = p;
    while (p)
    {
        if(p->next)
            p = p->next->next;
        else
            break;
        q = q->next;
    }
    return q->data;
}


void Middle2(struct Node* p) {
    Node* q = p;
    while (q) {
        q = q->next;
        if (q) q = q->next;
        if (q) p = p->next;
    }
    cout << "Middle Element is : " << p->data << endl; 
}

void Middle3(struct Node* p) {
/*
using stack
*/
    
}

int main() {
    int a[] = {2, 4, 6, 8, 10};
    int b[] = {1, 3, 5, 7, 9, 11};
    Create(a, 5);
    Display(first);
    cout << "Middle Element is : " << Middle1(first) << endl;
    Middle2(first);
    return 0;
}