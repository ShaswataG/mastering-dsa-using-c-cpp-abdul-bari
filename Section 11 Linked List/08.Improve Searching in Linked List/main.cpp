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
// Move to head
    struct Node* q;
    while (p) {
        if (key == p->data) {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        } else {
            q = p;
            p = p->next;
        }
    }
    return NULL;
}

void Display(struct Node* p) {
// TC = O(n)
// SC = O(1) doubt?
    cout << "First pointer stores address: " << p << endl; 
    while (p != NULL) {
        cout << "Address: " << p << " stores Value: " << p->data << endl;
        p = p->next;
    }
}

int main() {
    int a[] = {2, 3, 5, 7, 9};
    Create(a, 5);
    Display(first);
    cout << endl;
    cout << LSearch1(first, 7) << endl;
    Display(first);
    cout << endl;
    cout << LSearch1(first, -7) << endl;
    return 0;
}