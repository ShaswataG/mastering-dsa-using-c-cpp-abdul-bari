using namespace std;
#include<iostream>

struct Node
{
    int data;
    Node* next;
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

void Display1(struct Node* p) {
    do {
        cout << p->data << " ";
        p = p->next;
    } while(p != head);
    cout << endl;
}

// int flag = 0;

void Display2(struct Node* p) {
    static int flag = 0;
    if (p != head || flag == 0) {
        flag = 1;
        cout << p->data << " ";
        Display2(p->next);
    }
    flag = 0;
    cout << endl;
}

int main() {
    int a[] = {2, 3, 5, 7, 9};
    Create(a, 5);
    Display1(head);
    Display2(head);
    return 0;
}