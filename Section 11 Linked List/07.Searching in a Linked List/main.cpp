using namespace std;
#include<iostream>

struct Node {
    int data;
    struct Node* next;
}* first;

void Create(int a[], int n) {
    struct Node* temp,* last;
    first = new Node;
    first->data = a[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++) {
        temp = new Node;
        temp->data = a[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

struct Node* LSearch1(struct Node* p, int key) {
    while (p) {
        if (key == p->data) return p;
        p = p->next;
    }
    return NULL;
}

struct Node* LSearch2(struct Node* p, int key) {
    if (p == NULL) return NULL;
    if (key == p->data) return p;
    return LSearch2(p->next, key);
}

int main() {
    int a[] = {2, 3, 5, 7, 9};
    Create(a, 5);
    cout << LSearch1(first, 7) << endl;
    cout << LSearch1(first, -7) << endl;
    cout << LSearch2(first, 7) << endl;
    cout << LSearch2(first, -7) << endl;
    return 0;
}