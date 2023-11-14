using namespace std;
#include<iostream>
#include<queue>

struct TreeNode {
    int data;
    TreeNode* lchild, * rchild;
};

struct TreeNode* root;

void create() {
    queue<TreeNode*> q;
    TreeNode* t, * p;
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
        cout << "Enter left child : ";
        cin >> x;
        if (x != -1) {
            t = new TreeNode;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.push(t);
        }
        cout << "Enter right child : ";
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

void preorder(TreeNode* p) {
    if (p) {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void postorder(TreeNode* p) {
    if (p) {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << " ";
    }
}

void inorder(TreeNode* p) {
    if (p) {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}

int main() {
    create();
    preorder(root);
    return 0;
}