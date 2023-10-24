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

void Display1(struct Node* p) {
    do {
        cout << p->data << " ";
        p = p->next;
    } while(p != head);
    cout << endl;
}

int Delete1(struct Node* p, int index) {
/*
my trial
*/
    if (index < 1 || index > Length(p)) return -1;
    int x = -1;
    if (index == 1) {
        while (p->next != head) {
            p = p->next;
        }
        p->next = head->next;
        x = head->data;
        delete head;
        head = p->next;
    } else {
        Node* q;
        for (int i = 0; i < index - 1; i++) {
            q = p;
            p = p->next;
        }
        x = p->data;
        q->next = p->next;
        delete p;
    }
    return x;
}

int Delete2(struct Node* p, int index) {
/*
best case, TC = O(1) (when deleting second node)
worst case, TC = O(n) (when deleting any other node including first node)
*/   
    if (index < 1 || index > Length(p)) return -1;
    int x = -1;
    if (index == 1) {
        while (p->next != head) {
            p = p->next;
        }
        x = head->data;
        if (p == head) {
            delete head;
            head = NULL;
        } else {
            p->next = head->next;
            delete head;
            head = p->next;
        }
    } else {
        for (int i = 0; i < index - 2; i++) {
            p = p->next;
        }
        Node* q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}

int main() {
    int a[] = {1, 3, 5, 7, 9, 11, 13};
    Create(a, 7);
    Display1(head);
    Delete1(head, 3);
    Display1(head);
    Delete1(head, 4);
    Display1(head);
    Delete1(head, 1);
    Display1(head);
    return 0;
}