using namespace std;
#include<iostream>

struct Node {
    int data;
    Node* next;
}* first;

void Insert(Node* p, int x) {
    Node* t = new Node;
    t->data = x;
    t->next = NULL;
    if (!p) {
        first = t;
    } else {
        Node* q = NULL;
        while (p) {
            q = p;
            p = p->next;
        }
        q->next = t;
    }
}

int Delete(Node* p) {
    int x = -1;
    if (!p) {
        return x;
    } else {
        Node* t = p;
        first = p->next;
        x = p->data;
        delete t;
        return x;
    }
}

void BinSort(int a[], int n) {
    int max, i, j;
    Node** Bins;
    max = findMax(a, n);
    Bins = new Node*[max+1];
    for (int i = 0; i <= max; i++) Bins[i] = NULL;

    for (int i = 0; i < n; i++) {
        Insert(Bins[a[i]], a[i]);
    }
    i = 0, j = 0;
    while (i <= max) {
        while (Bins[i] != NULL) {
            a[j++] = Delete(Bins[i]);
        }
        i++;
    }
}

int findMax(int a[], int n) {
    int max = INT32_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] > max) max = a[i];
    }
    return max;
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {6, 2 ,1 ,9, 5, 4, 0, 11, 17}, n = 9;
    display(a, n);
    BinSort(a, n);
    display(a, n);
    return 0;
}