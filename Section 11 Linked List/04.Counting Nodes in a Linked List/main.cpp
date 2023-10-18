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
    for (int i = 2; i <= n; i++) {
        temp = new Node;
        temp->data = i*2;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

int Count1(struct Node* p) {
/*
TC = O(n)
SC = O(1)
*/
    int cnt = 0;
    while(p != NULL) {
        cnt++;
        p = p->next;
    }    
    return cnt;
}

int Count2(struct Node* p) {
/*
TC = O(n)
SC = O(n)
*/
    if (p == NULL) {
        return 0;
    } else {
        return Count2(p->next)+1;
    }
}

int Count3(struct Node* p) {
    int x = 0;
    if (p) {
        x = Count3(p->next);
        return x+1;
    } else return x;
}

void Display(struct Node* p) {
// TC = O(n)
// SC = O(1) doubt?
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    Create(7);
    Display(first);
    cout << "Number of nodes = " << Count1(first) << endl;
    cout << "Number of nodes = " << Count2(first) << endl;
    return 0;
}