using namespace std;
#include<iostream>

struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
} * first;

void Create(int a[], int n) {
    Node* temp, * last;
    first = new Node;
    first->data = a[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++) {
        temp = new Node;
        temp->data = a[i];
        temp->prev = last;
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void Display(struct Node* p) {
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int Length(struct Node* p) {
    int l = 0;
    while (p) {
        l++;
        p = p->next;
    }
    return l;
}

void Reverse(struct Node* p) {
    Node* temp;
    while (p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        if (!p->prev) first = p;    // my method of modifying first
        p = p->prev;
        if (p != NULL && p->next == NULL) first = p;    // abdul bari's method of modifying first
    }
}

int main() {
    int a[] = {2, 3, 5, 7, 9, 11};
    Create(a, 6);
    Display(first);
    Reverse(first);
    Display(first);
    cout << "first node has value : " << first->data << endl;
    return 0;
}