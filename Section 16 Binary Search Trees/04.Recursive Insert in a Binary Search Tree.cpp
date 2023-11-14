using namespace std;
#include<iostream>

struct Node {
    int data;
    Node* lchild, * rchild;
};

Node* root = NULL;

Node* insert(Node* p, int key) {
    Node* t;
    if (!p) {
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data) {
        p->lchild = insert(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = insert(p->rchild, key);
    }
    return p;
}

void Inorder(Node* p) {
    if (p) {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

Node* Search(Node* p, int key) {
    while (p) {
        if (key == p->data) return p;
        else if (key < p->data) p = p->lchild;
        else p = p->rchild; 
    }
    return NULL;
}

int main() {
    int a[] = {3, 1, 7, 10, 11, 0, 6, 1};
    int n = 8;
    for (int i = 0; i < n; i++) {
        if (!root) root = insert(root, a[i]);
        insert(root, a[i]);
    }
    cout << "Preorder: ";
    Inorder(root);
    cout << endl;

    Node* temp = Search(root, 10);
    if (temp == NULL) cout << "Element is not found.\n";
    else cout << temp->data << " is found at address " << temp << ".\n";
    return 0;
}