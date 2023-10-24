using namespace std;
#include<iostream>

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

void Reverse(struct Node* p) {
    int n = Count1(p);
    int* arr = new int[n];
    int i = 0;
    Node* q = p;
    while(q) {
        arr[i] = q->data;
        q = q->next;
        i++;
    }
    i--;
    q = p;
    while(q) {
        q->data = arr[i--];     // coping value of arr[i] in q->data and decrementing i at the same time
        // i--;
        q = q->next;
    }
}

int main() {
    int a[6] = {1,3,5,7,9,11};
    create(a, 6);
    Display(first);
    Reverse(first);
    Display(first);
    return 0;
}