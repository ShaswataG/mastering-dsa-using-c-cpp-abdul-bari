using namespace std;
#include<iostream>
#include<queue>

struct TreeNode {
    TreeNode* lchild, * rchild;
    int data;
};

class Tree {
    public:
        TreeNode* root;
        void create();
        int count(TreeNode* p);
        int sum(TreeNode* p);
        int countNodesWithDeg2(TreeNode* p);
};

void Tree::create() {
    queue<TreeNode*> q;
    TreeNode* p, * t;
    int x;
    cout << "Enter root value : ";
    cin >> x;
    root = new TreeNode;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.push(root);
    while (!q.empty()) {
        p = q.front();
        q.pop();
        cout << "Enter left child of " << p->data << " : ";
        cin >> x;
        if (x != -1) {
            t = new TreeNode;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.push(t);
        }
        cout << "Enter right child of " << p->data << " : ";
        cin >> x;
        if (x != -1) {
            t = new TreeNode;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.push(t);
        }
    }
}

int Tree::count(TreeNode* p) {
    int x, y;
    if (p) {
        x = count(p->lchild);
        y = count(p->rchild);
        return x+y+1;
    }
    return 0;
}

int Tree::sum(TreeNode* p) {
    int x, y;
    if (p) {
        x = sum(p->lchild);
        y = sum(p->rchild);
        return x+y+p->data;
    }
    return 0;
}

int Tree::countNodesWithDeg2(TreeNode* p) {
    int x, y;
    if (p) {
        x = countNodesWithDeg2(p->lchild);
        y = countNodesWithDeg2(p->rchild);
        if (p->lchild && p->rchild) return x+y+1;
        else return x+y;
    }
    return 0;
}



int main() {
    return 0;
}