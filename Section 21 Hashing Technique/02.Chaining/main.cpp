using namespace std;
#include<iostream>

struct Node {
    int data;
    Node* next;
};

void SortedInsert(Node** H, int x) {
    Node* t = new Node;
    t->data = x;
    t->next = NULL;
    if (!*H) {
        *H = t;
    } else {
        Node* p = *H;
        Node* q = NULL;
        while (p && x > p->data) {
            q = p;
            p = p->next;
        }
        if (p = *H) {
            *H = t;
            t->next = p;
        }
        if (q) {
            q->next = t;
            t->next = p;
        }
    }
}

Node* Search(Node* H, int key) {
    Node* p = H;
    while (p) {
        if (key == p->data) return p;
        p = p->next;
    }
    return NULL;
}

Node* Delete(Node** H, int key) {
    Node* p = *H;
    Node* q = NULL;
    Node* t;

    while (p && p->data != key) {
        q = p;
        p = p->next;
    }
    if (q) q->next = p->next;

    delete p;
}

int HashFunction(int x) {
    return x%10;
}

void Insert(Node* H[], int key) {
    SortedInsert(&H[HashFunction(key)], key);
}

void displayNodes(Node* p) {
    while (p) {
        cout << "->" << p->data;
        p = p->next;
    }
    cout << endl;
}

void displayTable(Node* HT[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "HT[" << i << "]";
        displayNodes(HT[i]);
        cout << endl;
    }
}

int main() {
    Node* HT[10];
    for (int i = 0; i < 10; i++) {
        HT[i] = NULL;
    }

    int a[] = {3, 1, 43, 23, 12, 55, 2, 7, 13, 90}, n = 10;
    for (int i = 0; i < n; i++) {
        Insert(HT, a[i]);
    }

    Node* temp = Search(HT[HashFunction(33)], 3);
    if (!temp) {
        cout << "Not found" << endl;
    } else {
        cout << temp->data << endl;    
    }
    
    // displayTable(HT, 10);    // not working, infinite loop
    

    return 0;
}