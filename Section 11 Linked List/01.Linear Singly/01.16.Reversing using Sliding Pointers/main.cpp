using namespace std;
#include<iostream>

/*
Priority: Reverse using sliding pointers > Reverse by copying elements (for ex: using array)
Reason: suppose instead of int data, node contains structure containing multiple data, in that case, copying multiple data in each nodes will require lots of memory
So, Reverse using sliding pointers is preferred, since a pointer only takes 2 & 4 bytes in 32 & 64 bit compilers respectively
*/

struct Node {
    int data;
    struct Node* next;
} * first;

void create(int a[], int n) {
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

void Reverse(Node* p) {
    p = first;
    Node* q = NULL, * r = NULL;
    while(p) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

int main() {
    int a[6] = {0, 2, 4, 6, 8, 10};
    create(a, 6);
    Display(first);
    Reverse(first);
    Display(first);
    return 0;
}