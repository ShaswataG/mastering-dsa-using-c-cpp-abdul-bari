using namespace std;
#include<iostream>

struct Node {
    int data;
    struct Node* next; 
}* first = NULL;

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
}

int main() {
    int A[] = {3, 5, 7, 10, 15};
    struct Node* p;
    create(A, 5);
    Display(first);
    return 0;
}