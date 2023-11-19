using namespace std;
#include<iostream>
#include<stack>

/*
BST can be generated if any one is given- preorder or postorder
inorder is not required because inorder of a BST is the elements of the BST in sequence
*/

struct Node {
    int data;
    Node* lchild, * rchild;
};

void createIn(int pre[], int n) {
/*
Doubt- not matching with abdul bari's code
TC = O(n)
*/
    stack<Node*> s;
    Node* t, * p, * root;
    int i = 0;
    root = new Node; root->data = pre[i++], root->lchild = root->rchild = NULL;
    p = root;
    s.push(p);
    while (i < n) {
        if (pre[i] < p->data) {
            t = new Node; t->data = pre[i++]; t->lchild = t->rchild = NULL;
            p->lchild = t;
            s.push(p);
            p = t;
        } else if (pre[i] > p->data && s.empty()) {
            t = new Node; t->data = pre[i++]; t->lchild = t->rchild = NULL;
            p->rchild = t;
            p = t;
        } else if (pre[i] > p->data && pre[i] < s.top()->data) {
            t = new Node; t->data = pre[i++]; t->lchild = t->rchild = NULL;
            p->rchild = t;
            p = s.top();
            s.pop();    
        }
    }
}

int main() {
    return 0;
}