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
        int count(Node* p);
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

int Tree::count(Node* p) {
    if (!p) return 0;
    return count(p->lchild)+count(p->rchild)+1;
}

int Tree::countNodesDegree2(Node* p) {
    if (!p) return 0;
    else if (p->lchild && p->rchild) return count(p->lchild)+count(p->rchild)+1;
    else return count(p->lchild)+count(p->rchild);
}

int Tree::countNodesDegree1(Node* p) {
    if (!p) return 0;
    else if ((p->lchild && !p->rchild) || (!p->lchild && p->rchild)) return countNodesDegree1(p->lchild)+countNodesDegree1(p->rchild)+1;
    else return countNodesDegree1(p->lchild)+countNodesDegree1(p->rchild);
}

int Tree::countNodesDegree1or2(Node* p) {
    if (!p) return 0;
    else if (p->lchild || p->rchild) return countNodesDegree1or2(p->lchild)+countNodesDegree1or2(p->rchild)+1;
    else return countNodesDegree1or2(p->lchild)+countNodesDegree1or2(p->rchild);
}

int Tree::countLeafNodes(Node* p) {
    if(!p) return 0;
    else if (!p->lchild && !p->rchild) return countLeafNodes(p->lchild)+countLeafNodes(p->rchild)+1;
    else return countLeafNodes(p->lchild)+countLeafNodes(p->rchild);
}

int main() {
    return 0;
}