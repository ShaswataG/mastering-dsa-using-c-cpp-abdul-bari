using namespace std;
#include<iostream>

struct Node {
    int data;
    Node* lchild, * rchild;
};

void Insert(Node* t, int key) {
    Node* r = NULL;
    if (!t) {
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return;
    }
    while (t) {
        r = t;
        if (key == t->data)
            return;
        else if (key < t->data) {
            t = t->lchild;
        } else {
            t = t->rchild;
        }
    }
    t = new Node;
    t->data = key;
    t->lchild = t->rchild = NULL;
    if (t->data < r->data) r->lchild = t;
    else r->rchild = t;  
}

int main() {
    return 0;
}