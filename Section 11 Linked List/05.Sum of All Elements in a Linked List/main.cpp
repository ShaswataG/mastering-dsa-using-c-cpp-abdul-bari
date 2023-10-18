using namespace std;
#include<iostream>

struct Node {
    int data;
    struct Node* next;
}* first; 

void Create(int n) {
    struct Node* temp, * last;
    first = new Node;
    first->data = 1;
    first->next = NULL;
    last = first;
    for(int i = 2; i <= n; i++) {
        temp = new Node;
        temp->data = i;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

int Sum1(struct Node* p) {
/*
Using iteration
TC = O(n)
SC = O(1)    
*/
    int total = 0;
    while(p) {
        total += p->data;
        p = p->next;
    }
    return total;
}

int Sum2(struct Node* p) {
/*
Using Recursion
TC = O(n)
SC = O(n)    
*/
    if (!p) return 0;
    else return p->data + Sum2(p->next);
}

int main() {
    Create(6);
    cout << "Sum of first 6 natural numbers = " << Sum1(first) << endl;
    cout << "Sum of first 6 natural numbers = " << Sum2(first) << endl;
    return 0;
}