using namespace std;
#include<iostream>

struct Node {
    int data;
    Node* next;
};

void SortedInsert(Node** p, int x) {
    Node* t = new Node;
    t->data = x;
    t->next = NULL;
    if (!p) {
        *p = t;
    } else {
        Node* r = *p;
        Node* q = NULL;
        while (r && x > r->data) {
            q = r;
            r = r->next;
        }
        if (r = *p)
            *p = t;
        t->next = r;
        if (q) q->next = t;
    }
}

Node* Search(Node** H, int key) {
    Node* p = *H;
    while (p) {
        if (key == p->data) return p;
        p = p->next;
    }
    return NULL;
}

Node* Delete(Node** H, int key) {
    Node* p = *H;
    Node* q = NULL;
    while (p) {
        q = p;
        if (key == p->data) {
            Node* t = p;
            int x = t->data;
        }
    }
}

int HashFunction(int x) {
    return x%10;
}

void Insert(Node* H[], int key) {
    SortedInsert(&H[HashFunction(key)], key);
}

int main() {
    Node* H[10];
    // int a[] = {3, 1, 43, 23, 12, 55, 2, 7, 13, 90, n = 10};
    // for (int i = 0; i < n; i++) {
    //     SortedInsert(H[HashFunction(a[i])], a[i]);
    // }
    
    return 0;
}