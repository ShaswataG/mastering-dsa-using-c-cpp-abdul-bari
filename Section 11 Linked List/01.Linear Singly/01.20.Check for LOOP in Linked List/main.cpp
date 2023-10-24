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

int isLoop(struct Node* f) {
    struct Node * p, * q;
    p = q = f;
    do {
        p = p->next;
        q = q->next;
        q = q? q->next : q; 
    } while(p && q && p != q);
    if (p == q) return 1;
    else return 0;
}


int main() {
    struct Node* t1, * t2;
    int a[] = {10, 20, 30, 40, 50};
    Create(a, 5);

// below three statements make the linked list a loop
    // t1 = first->next->next;
    // t2 = first->next->next->next->next;
    // t2->next = t1;
    cout << isLoop(first);
    return 0;
}