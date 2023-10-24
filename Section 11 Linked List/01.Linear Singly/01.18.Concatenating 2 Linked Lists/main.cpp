using namespace std;
#include<iostream>

struct Node {
    int data;
    struct Node* next;
} * first, * second;

void Create1(int a[], int n) {
    Node* t, * last;
    first = new Node;
    first->data = a[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }   
}

void Create2(int a[], int n) {
    Node* t, * last;
    second = new Node;
    second->data = a[0];
    second->next = NULL;
    last = second;
    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    
}

void Display(struct Node* p) {
// TC = O(n)
// SC = O(1) doubt?
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int Count1(struct Node* p) {
/*
TC = O(n)
SC = O(1)
*/
    int cnt = 0;
    while(p != NULL) {
        cnt++;
        p = p->next;
    }    
    return cnt;
}

void Concatenate(struct Node* p) {
    while(p->next) {
        p = p->next;
    }
    p->next = second;
};

int main() {
    int a[] = {0, 1, 2, 3, 4};
    int b[] = {5, 6, 7, 8, 9, 10};
    Create1(a, 5);
    Create2(b, 6);
    Display(first);
    Display(second);
    Concatenate(first);
    Display(first);
    return 0;
}