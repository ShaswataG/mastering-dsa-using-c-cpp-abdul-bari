using namespace std;
#include<iostream>

struct Node {
    int data;
    struct Node* next;
}* first;

void Create(int a[], int n) {
    first = new Node;
    Node* last;
    first->data = a[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++) {
        Node* temp = new Node;
        temp->data = a[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
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

int Delete(struct Node* p, int index) {
/*
min TC = O(1)
max TC = O(n)
*/
    Node* q = NULL;
    int x = -1;
    if (index < 1 || index > Count1(first)) return -1;
    if (index == 1) {
        q = first;
        x = first->data;
        first = first->next;
        delete q;
        return x;
    } else if (index > 1) {
        for (int i = 0; i < index-1 && p; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
    return index;
}

void Display(struct Node* p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int a[] = {2, 3, 5, 7, 9};
    Create(a, 5);
    Display(first);
    
    Delete(first, 4);
    Display(first);
    
    Delete(first, 1);
    Display(first);
    
    Delete(first, 3);
    Display(first);
}