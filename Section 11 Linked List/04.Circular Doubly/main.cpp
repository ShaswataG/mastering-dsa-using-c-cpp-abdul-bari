using namespace std;
#include<iostream>

struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
} * head;

void Create(int a[], int n) {
    Node* t, * last;
    head = new Node;
    head->data = a[0];
    head->prev = NULL;
    head->next = NULL;
    last = head;
    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = a[i];
        t->prev = last;
        t->next = last->next;
        last->next = t;
        last = t;
    }
    last->next = head;
}

void Display(struct Node* p) {
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
}

int Length(struct Node* p) {
    int l = 0;
    while (p) {
        l++;
        p = p->next;
    }
    return l;
}

void Insert(struct Node* p, int index, int x) {
/*
best case, TC = O(1) while inserting before head node
worst case, TC = O(n) while inserting at any other node
*/
    Node* t;
    if (index < 0 || index > Length(p)) return;
    if (index == 0) {
        t = new Node;
        t->data = x;
        t->prev = head->prev;
        t->next = head->next;
        head->prev->next = t;
        head = t;
        // while (p->next != NULL) {
        //     p = p->next;
        // }
        // p->next = head;
    } else {
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        }
        t = new Node;
        t->data = x;
        p->next = t;
        t->prev = p;
        t->next = p->next;
        t->next->prev = t;
    }
}

int main() {
    int a[] = {1, 4, 6, 3, 10};
    Create(a, 5);
    Display(head);
    Insert(head, 5, 73);
    Display(head);
    Insert(head, 0, 42);
    Display(head);
    Insert(head, 3, 56);
    Display(head);
    return 0;
}