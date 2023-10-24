using namespace std;
#include<iostream>

struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
} * first = NULL;

void Create(int a[], int n) {
    Node* temp, * last;
    first = new Node;
    first->data = a[0];     
    first->prev = first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++) {
        temp = new Node;
        temp->prev = last;
        temp->data = a[i];
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
    while(p) {
        l++;
        p = p->next;
    }
    return l;
}

int Delete(struct Node* p, int index) {
/*
best case, TC = O(1)
worst case, TC = O(n)
*/
    int x = -1;
    if (index == 1) {
        first = first->next;
        if (first != NULL)
            first->prev = NULL;
            // first->next->prev = first;
        x = p->data;
        delete p;
    } else {
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
    return x;
}

int main() {
    int a[] = {1, 3, 5, 7, 9, 11};
    Create(a, 6);
    Display(first);
    Delete(first, 0);
    Display(first);
    Delete(first, 5);
    Display(first);
    return 0;
}