
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

// My trial
bool CheckSorted1(struct Node* p) {
    Node* q = p;
    while(p) {
        if (q->data > p->data) return false;
        q = p;
        p = p->next;
    }
    return true;
}

bool CheckSorted2(struct Node* p) {
/*
max TC = O(n)
min TC = O(1)
*/
    int x = INT16_MIN;
    while(p) {
        if (x > p->data) return false;
        x = p->data;
        p = p->next;
    }
    return true;
}

void Display(struct Node* p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int a[] = {2, 30, 5, 7, 9};
    Create(a, 5);
    Display(first);
    cout << CheckSorted1(first);
    cout << endl;
    cout << CheckSorted2(first);
}