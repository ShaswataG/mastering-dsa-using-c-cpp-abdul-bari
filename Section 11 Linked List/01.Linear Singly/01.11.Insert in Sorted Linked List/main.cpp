using namespace std;
#include<iostream>

struct Node {
    int data;
    struct Node* next;
}* first;

void Create(int a[], int n) {
    first = new Node;
    Node* last;
    first->data = a[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++) {
        Node* temp = new Node;
        temp->data = a[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}   

void SortedInsert(struct Node* p, int x) {
    Node* t, * q = NULL;
    t = new Node;
    t->data = x;
    t->next = NULL;
    if (!first) {
        first = t;
    } else {
        while (p && p->data < x) {
            q = p;
            p = p->next;
        }
        if (p == first) {
            t->next = first;    // doubt
            // p = t;
            first = t;
        } else {
            t->next = q->next;
            q->next = t;
        }
    }
}

void Display(struct Node* p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int a[] = {2, 3, 5, 7, 9};
    Create(a, 5);
    Display(first);
    SortedInsert(first, 4);
    Display(first);
    SortedInsert(first, 1);
    Display(first);
    SortedInsert(first, 11);
    Display(first);
    return 0;
}