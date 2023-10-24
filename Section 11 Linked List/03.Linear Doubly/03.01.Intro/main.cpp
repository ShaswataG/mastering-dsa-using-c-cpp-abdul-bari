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

int main() {
    int a[] = {5, 10, 15, 20, 25, 30};
    Create(a, 6);
    Display(first);
    cout << Length(first) << endl;
    return 0;
}