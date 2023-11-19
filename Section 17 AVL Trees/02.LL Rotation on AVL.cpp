using namespace std;
#include<iostream>

struct Node {
    int data, height;
    Node* lchild, * rchild;
};

int NodeHeight(Node* p) {
    int x, y;
    if (!p) return 0;
    else {
        x = NodeHeight(p->lchild);
        y = NodeHeight(p->rchild);
        return (x > y) ? x+1 : y+1;
    }
}

Node* RInsert(Node* p, int key) {
    if (!p) {
        Node* t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data) p->lchild = RInsert(p->lchild, key);
    else if (key > p->data) p->rchild = RInsert(p->rchild, key);
    return p;
}

int main() {
    return 0;
}