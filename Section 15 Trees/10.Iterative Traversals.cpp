using namespace std;
#include<iostream>
#include<stack>
#include<queue>

struct Node {
    int data;
    Node* lchild, * rchild;
};

class Tree {
    public:
        Node* root;
    void create();
    void preorder();
    void inorder();
    void levelorder();

};

void Tree::create() {
    Node* t, * p;
    queue<Node*> q;
    int x;
    cout << "Enter root value : ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.push(root);
    while (!q.empty()) {
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
        cout << "Enter right child of " << p->data << ": ";
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

void Tree::preorder() {
/*
TC = O(n)
stack size depends on height
*/
    stack<Node*> s;
    Node* t = root;
    cout << "Preorder : ";
    while (t!= NULL || !s.empty()) {
        if (t) {
            s.push(t);
            cout << t->data << " ";
            t = t->lchild;
        } else {
            t = s.top();
            s.pop();
            t = t->rchild;
        }
    }
    cout << endl;
}

void Tree::inorder() {
/*
TC = O(n)
stack size depends on height
*/
    stack<Node*> s;
    Node* t = root;
    cout << "Inorder : ";
    while (t != NULL || !s.empty()) {
        if (t) {
            s.push(t);
            t = t->lchild;
        } else {
            t = s.top();
            s.pop();
            cout << t->data << " ";
            t = t->rchild;
        }
    }
    cout << endl;
}

void Tree::levelorder() {
/*
TC = O(n)
stack size depends on height
*/
    Node* t = root;
    queue<Node*> q;
    q.push(root);
    cout << "Levelorder : ";
    cout << root->data << " ";
    while (!q.empty()) {
        t = q.front();
        q.pop();
        if (t->lchild) {
            cout << t->lchild->data << " ";
            q.push(t->lchild);
        }
        if (t->rchild) {
            cout << t->rchild->data << " ";
            q.push(t->rchild);
        }
    }
    cout << endl;
}

int main() {
    Tree t;
    t.create();
    t.preorder();
    t.inorder();
    t.levelorder();
    return 0;
}