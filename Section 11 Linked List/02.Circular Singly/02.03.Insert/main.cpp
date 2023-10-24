using namespace std;
#include<iostream>

struct Node {
    int data;
    struct Node* next;
} * head;

void Create(int a[], int n) {
    Node* temp, * last;
    head = new Node;
    head->data = a[0];
    head->next = head;
    last = head;
    for (int i = 1; i < n; i++) {
        temp = new Node;
        temp->data = a[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
    last->next = head;
}

int Length(struct Node* p) {
    int l = 0;
    do {
        l++;
        p = p->next;
    } while (p != head);
    return l;
}

void Insert(struct Node* p, int index, int x) {
/*
Inserting before head node and inserting after last node is the same
best case, TC = O(1) (insert just after first node)
worst case, TC = O(n) (any other position, including before the head node and any other node)
*/
    if (index < 0 || index > Length(p)) return;
    Node* t;
    if(index == 0) {
        t = new Node;
        t->data = x;
        if (head == NULL) {
            head = t;
            head->next = head;
        } else {
            while (p->next != head) {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;   // changing the head node is optional
        }
    } else {
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        }
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

void Display1(struct Node* p) {
    do {
        cout << p->data << " ";
        p = p->next;
    } while(p != head);
    cout << endl;
}

int main() {
    int a[] = {2, 3, 5, 7, 9};
    Create(a, 5);
    Display1(head);
    Insert(head, 2, 63);    // doubt- inserting at wrong index
    Display1(head);
    Insert(head, 0, 42);    
    Display1(head);
    Insert(head, -3, 63);
    Display1(head);
    cout << Length(head) << endl;
    return 0;
}