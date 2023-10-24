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

void Display(struct Node* p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
} 

void RemoveDuplicates(struct Node* p) {
    Node* q = p->next;
    while(q) {
        if (q->data != p->data) {
            p = q;
            q = p->next;
        } else {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

int main() {
    int a[] = {3, 5, 5, 7, 9, 9};
    Create(a, 6);
    Display(first);
    RemoveDuplicates(first);
    Display(first);
}