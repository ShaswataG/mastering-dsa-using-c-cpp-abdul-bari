using namespace std;
#include<iostream>

struct Node {
    int data;
    struct Node* next;
} * p, * q, * third = NULL, * last = NULL, * first, * second;

void Create1(int a[], int n) {
    Node* t, * last;
    p = new Node;
    p->data = a[0];
    p->next = NULL;
    last = p;
    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Create2(int a[], int n) {
    Node* t, * last;
    q = new Node;
    q->data = a[0];
    q->next = NULL;
    last = q;
    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    
}

void Display(struct Node* p) {
// TC = O(n)
// SC = O(1) doubt?
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void Merge(Node* p, Node* q) {
/*
TC = O(m+n)
where,
    m = number of nodes in p linked list
    n = number of nodes in q linked list
*/  
    if (p->data < q->data) {
        third = p;
        last = p;
        p = p->next;
        third->next = NULL;
    } else {
        third = q;
        last = q;
        q = q->next;
        third->next = NULL;
    }
    while(p != NULL && q != NULL) {
        if (p->data < q->data) {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        } else {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p) last->next = p;
    if (q) last->next = q;
}

int main() {
    int a[] = {1, 7, 5, 3, 4};
    int b[] = {3, 10, 6, 4, 13};
    Create1(a, 5);
    Create2(b, 5);
    Display(p);
    Display(q);
    Merge(first, second);
    Display(third);
    return 0;
}