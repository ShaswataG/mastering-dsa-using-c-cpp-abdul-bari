using namespace std;
#include<iostream>

struct Queue {
    int rear;
    int size;
    int* s;
};

void Create(Queue* q) {
    q->rear = -1;
    cout << "Enter size: ";
    cin >> q->size;
    q->s = new int[q->size];
}

void Enqueue(Queue* q, int x) {
    q->rear++;
    q->s[q->rear] = x;
}

void Dequeque(Queue* q) {
    for (int i = 0; i <= q->rear; i--) {
        q->s[i] = q->s[i+1];
    }
    q->rear--;
}

int main() {
    return 0;
}