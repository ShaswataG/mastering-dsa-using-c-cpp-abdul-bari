using namespace std;
#include<iostream>

struct Node {
    int data;
    struct node* next;
};

int main() {
    struct Node* p;
    // p = (struct node*) malloc(sizeof(struct node));
    p = new Node;
    p->data = 32;
    p->next = 0;
    return 0;
}