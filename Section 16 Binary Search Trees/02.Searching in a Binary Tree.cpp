using namespace std;
#include<iostream>

/*
TC - O(h)
logn <= h <= n
so, TC = O(logn)

while converting a tail recursion into a loop, stack is not required
*/

struct Node {
    int data;
    Node* lchild, * rchild;
};

Node* root = NULL;

Node* RSearch(Node* t, int key) {
    if (!t) {
        return NULL;
    }
    if (key == t->data) {
        return t;
    } else if (key < t->data) {
        return RSearch(t->lchild, key);
    } else {
        return RSearch(t->rchild, key);
    }
}

Node* ISearch(Node* t, int key) {
    while (t) {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}

int main() {

}