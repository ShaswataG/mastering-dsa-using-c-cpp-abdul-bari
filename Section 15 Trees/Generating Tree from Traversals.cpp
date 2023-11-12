using namespace std;
#include<bits/stdc++.h>

struct Node {
    int data;
    Node* lchild, * rchild;
};

class Tree {
    public:
        void create();
};

Node* root;

void Tree::create() {
    Node* t, * p;
    queue<Node*> q;
    int x;
    cout << "Enter root value : ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    p = root;
    q.push(p);
    while(!q.empty()) {
        p = q.front();
        q.pop();
        cout << "Enter left child of " << p->data << ": ";
        cin >> x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.push(t);
        }
        cout << "Enter right of " << p->data << ": ";
        cin >> x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.push(t);
        }
    }
}

int main() {
    return 0;
}