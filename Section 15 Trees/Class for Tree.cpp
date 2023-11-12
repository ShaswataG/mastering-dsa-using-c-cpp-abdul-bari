using namespace std;
#include<iostream>
#include<queue>

struct Node {
    int data;
    Node* lchild, * rchild;
};

/*
TC = O(n)
    no of function calls  = no. of nodes + no. null pointers = n + (n+1)
    size of stack ~ h+2 (depends on height)
SC = O(n) (h is replaced by n, we don't write O(h))
    we know, logn <= h <= n
*/

class Tree {
    public:
        Node* root;
        Tree() {root = NULL;}
        void Create();
        void Preorder(Node* p);
        void Postorder(Node* p);
        void Inorder(Node* p);
        void Levelorder(Node* p);
        int Height(Node* p);
};

void Tree::Create() {
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
        cout << "Enter left child of " << p->data << " : ";
        cin >> x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.push(t);
        }
        cout << "Enter right child " << p->data << " : ";
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

void Tree::Preorder(Node* p) {
    cout << "Preorder : ";
    if (p) {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
    cout << endl;
}

void Tree::Postorder(Node* p) {
    cout << "Postorder : ";
    if (p) {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }
    cout << endl;
}

void Tree::Inorder(Node* p) {
    cout << "Inorder : ";
    if (p) {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
    cout << endl;
}

void Tree::Levelorder(Node* p) {
    queue<Node*> q;
    cout << p->data << " ";
    q.push(p);
    cout << "Levelorder : ";
    while (!q.empty()) {
        p = q.front();
        q.pop();
        if (p->lchild) {
            cout << p->lchild->data << " ";
            q.push(p->lchild);
        }
        if (p->rchild) {
            cout << p->rchild->data << " ";
            q.push(p->rchild);
        }
    }
    cout << endl;
}

int Tree::Height(Node* p) {
    int x = 0, y = 0;
    if (root == NULL) {
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    if (x > y) return x+1;
    else return y+1;
}



int main() {
    Tree t;
    t.Create();
    t.Preorder(t.root);
    t.Postorder(t.root);
    t.Inorder(t.root);
    t.Levelorder(t.root);
    return 0;
}