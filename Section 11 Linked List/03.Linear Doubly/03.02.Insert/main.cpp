using namespace std;
#include<iostream>

struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
} * first = NULL;

void Create(int a[], int n) {
    Node* temp, * last;
    first = new Node;
    first->data = a[0];     
    first->prev = first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++) {
        temp = new Node;
        temp->prev = last;
        temp->data = a[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void Display(struct Node* p) {
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }   
    cout << endl;
}

int Length(struct Node* p) {
    int l = 0;
    while(p) {
        l++;
        p = p->next;
    }
    return l;
}

void Insert(Node* p, int index, int x) {
/*
worst case, TC = O(n)
best case, TC = O(1)
*/
    if (index < 0 || index > Length(p)) return;
    Node* t;
    if (index == 0) {
        t = new Node;
        t->prev = NULL;
        t->data = x;
        t->next = first;
        first->prev = t;
        first = t;
    } else {
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        }
        t = new Node;
        t->prev = p;
        t->data = x;
        t->next = p->next;
        if (p->next) {
            p->next->prev = t;
        }
        p->next = t;
    }
}

int main() {
    int a[] = {10, 20, 30, 40, 50};
    Create(a, 5);
    Display(first);
    Insert(first, 0, 22);
    Display(first);
    Insert(first, 1, 25);
    Display(first);
    Insert(first, 7, 53);
    Display(first);
    return 0;
}