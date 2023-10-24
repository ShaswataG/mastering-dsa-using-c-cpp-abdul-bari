using namespace std;
#include<iostream>

struct Node {
    int data;
    struct Node* next;
}* first, * last;

void InsertLast(int x) {
    Node* t = new Node;
    t->data = x;
    t->next = NULL;
    if (first == NULL) {
        first = last = t;
    } else {
        last->next = t;
        last = t;
    }
}
/*
my trial - segmentation fault
void Insert(int x) {
    Node* t = new Node;
    t->data = x;
    t->next = NULL;
    if (first == NULL) {
        first = t;
    } else {
        Node* p = first;
        for (int i = 0; p; i++) {
            p = p->next;
        }
        p->next = t;
    }
}
*/
void Display(struct Node* p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    Display(first);
    InsertLast(2);
    Display(first);
    InsertLast(3);
    Display(first);
    InsertLast(5);
    Display(first);
    InsertLast(7);
    Display(first);

    // Display(first);
    // Insert(2);
    // Display(first);
    // Insert(3);
    // Display(first);
    // Insert(5);
    // Display(first);
    // Insert(7);
    // Display(first);
    // Insert(11);
    // Display(first);
    return 0;
}