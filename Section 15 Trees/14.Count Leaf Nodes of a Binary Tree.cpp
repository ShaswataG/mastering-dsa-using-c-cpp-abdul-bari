using namespace std;
#include<iostream>
#include<queue>

struct Node {
    int data;
    Node* lchild, * rchild;
};

class Tree {
    public:
        Node* root;
        void create();
        int countLeafNodes(Node* p);
        int countNodesDegree2(Node* p);
        int countNodesDegree1(Node* p);
        int countNodesDegree1or2(Node* p);
};

void Tree::create() {
    root = new Node;
    Node* p,* t;
    queue<Node*> q;
    int x;
    cout << "Enter root value : ";
    cin >> x;
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
            q.push(t);
        }
        cout << "Enter right child of " << p->data << " : ";
        cin >> x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            q.push(t);
        }
    }
}

int Tree::countNodesDegree2(Node* p) {
    int x, y;
    if (p) {
        x = countNodesDegree2(p->lchild);
        y = countNodesDegree2(p->rchild);
        if (p->lchild && p->rchild) return x+y+1;
        else return x+y;
    }
    return 0;
}

int Tree::countNodesDegree1(Node* p) {
    int x, y;
    if (p) {
        x = countNodesDegree1(p->lchild);
        y = countNodesDegree1(p->rchild);
        if ((p->lchild && !p->rchild) || (!p->lchild && p->rchild)) return x+y+1;
        else return x+y;

        // if (p->lchild ^ p->rchild) return x+y+1;
        // else return x+y;
    }
    return 0;
}

int Tree::countNodesDegree1or2(Node* p) {
    int x, y;
    if (p) {
        x = countNodesDegree1or2(p->lchild);
        y = countNodesDegree1or2(p->rchild);
        if (p->lchild || p->rchild) return x+y+1;
        else return x+y;
    }
    return 0;
}

int Tree::countLeafNodes(Node* p) {
    int x, y;
    if (p) {
        x = countLeafNodes(p->lchild);
        y = countLeafNodes(p->rchild);
        if (!p->lchild && !p->rchild) return x+y+1;
        else return x+y;
    }
    return 0;
}

int main() {
    return 0;
}