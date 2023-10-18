using namespace std;
#include<iostream>

struct Node {
    int data;
    struct Node* next;
}* first;

int Count1(struct Node* p) {
    int cnt = 0;
    while(p != NULL) {
        cnt++;
        p = p->next;
    }    
    return cnt;
}


void Insert(struct Node* p, int pos, int x) {
/*
Best case, TC = O(1)
Worst case, TC = O(n), where n = pos (pos = position after which we want to insert node)
*/
    if (pos < 0 || pos > Count1(p)) return;
    Node* t;
    if (pos == 0) {
        t = new Node;
        t->data = x;
        t->next = first;
        first = t;
        p = first;
    } else if (pos > 0) {
        p = first;
        for (int i = 0; i < pos-1 && p; i++) {
            p = p->next;
        }
        if (p) {
            t = new Node;
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
    }
}

void Display(struct Node* p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    cout << first << endl;
    Display(first);
    Insert(first, 0, 16);
    Display(first);
    Insert(first, 1, 13);
    Display(first);
    Insert(first, 2, 42);
    Display(first);
    Insert(first, 3, 57);
    Display(first);
    Insert(first, 0, 42);
    Display(first);
    return 0;
}