using namespace std;
#include<iostream>

struct Node {
    int data;
    Node* lchild, * rchild;
};

int height(Node* p) {
    int x, y;
    if (!p) return -1;  // assuming height is 0 at root level, disadvantage- when root node = NULL, height = -1
    // if (!p) return 0;   // assuming height is 1 at root level
    x = height(p->lchild);
    y = height(p->rchild);
    return (x > y) ? x+1 : y+1;
}

int main() {
    return 0;
}