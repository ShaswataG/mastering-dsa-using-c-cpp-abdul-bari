using namespace std;
#include<iostream>

struct Node {
    int data;
    struct Node* next;
}* first;

void Create(int a[], int n) {    Node* t, * last;
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

int Max1(struct Node* p) {
/*
Iterative
TC = O(n)
SC = O(1)
*/
    int max = INT16_MIN;
    while (p) {
        if (p->data > max) max = p->data;
        p = p->next;
    }
    return max;
}

int Max2(struct Node* p) {
/*
Recursive
*/
    int x = 0;
    if (p == 0) return INT16_MIN;
    else {
        x = Max2(p->next);
        if (x > p->data) return x;
        else return p->data;
    }
}

int Max3(struct Node* p) {
/*
Recursive
*/
    int x = 0;
    if (p == 0) return INT16_MIN;
    x = Max2(p->next);
    return (x > p->data) ? x : p->data;
}

int main() {
    int a[] = {3, 5, 19, 12, 43, 1, 77, 2};
    Create(a, 8);
    cout << "Maximum Element of the Linked List = " << Max1(first) << endl;
    cout << "Maximum Element of the Linked List = " << Max2(first) << endl;
    cout << "Maximum Element of the Linked List = " << Max3(first) << endl;
    // cout << INT16_MIN;
    return 0;
}