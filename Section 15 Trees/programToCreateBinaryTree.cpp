using namespace std;
#include<iostream>

template<class T>
struct QNode {
    T data;
    struct QNode*;
};

template<class T>
class Queue {
    struct QNode<T>* front, * rear;
    front = rear = NULL;
public:
    void enqueue(int);
    T dequeue();
    int isEmpty();
};

template<class T>
void Queue<T>::enqueue(int x) {
    QNode* t = new QNode<T>;
    t->data = x;
    t->next = NULL;
    if (!front) {
        front = rear = t;
    } else {
        rear->next = t;
        rear = t;
    }
}

template<class T>
T Queue<T>::dequeue() {
    int x = -1;
    if (front) {
        x = front->data;
        QNode* t = front;
        front = front->next;
        delete t;
    } else {
        return -1;
    }
    return x;
}

template<class T>
int Queue<T>::isEmpty() {
    if (!front) return 1;
    else return 0;
}

template<class T>
struct Node {
    T data;
    Node* lchild, * rchild;
};

template<class T>
struct Node* root;

template<class T>
void create() {
    Node<T>* p, * t;
    T x;
    Queue<Node*> q;
    cout << "Enter root value : ";
    cin >> x;
    root = new Node<T>;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    while (!q.isEmpty()) {
        p = q.dequeue();
        cout << "Enter left child : ";
        cin >> x;
        if (x != -1) {
            t = new Node<T>;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(t);
        }
        cout << "Enter right child : ";
        cin >> x;
        if (x != -1) {
            t = new Node<T>;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(t);
        }
    }
}

template<class T>
void preorder(struct Node* p) {
    if (p) {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main() {
    create<int>();
    preorder<int>(root<int>);

    return 0;
}