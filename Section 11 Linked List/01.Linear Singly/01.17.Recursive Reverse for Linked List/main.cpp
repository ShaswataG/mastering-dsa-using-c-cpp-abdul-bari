using namespace std;
#include<iostream>

struct Node {
    int data;
    struct Node* next;
} * first;

void create(int a[], int n) {
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

void Reverse(Node* q, Node* p) {
    if (p) {
        Reverse(p, p->next);
        p->next, q;     // doubt
    } else {
        first = q;
    }
}

int main() {
    int a[5] = {2, 3, 5, 7, 9};
    create(a, 5);
    Display(first);
    Reverse(NULL, first);
    Display(first);
    return 0;
}