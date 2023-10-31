using namespace std;
#include<iostream>

struct Queue {
    int size;
    int front, rear;    // index pointers
    int* Q;
};

void Create(Queue* q) {
    cout << "Enter size: ";
    cin >> q->size;
    q->Q = new int[q->size];
    q->front = q->rear = -1; 
}

void Enqueue(Queue* q, int x) {
    if (q->rear == q->size-1) {
        cout << "Queue is full!" << endl;
        return;
    }
    q->rear++;
    q->Q[q->rear] = x;
}

int Dequeue(Queue* q) {
    int x = -1;
    if (q->front == q->rear) {
        cout << "Queue is empty!" << endl;
        return x;
    }
    q->front++;
    x = q->Q[q->front];
    // q->Q[q->front] = 0;     // doubt- abdul bari doesn't assign it 0
    return x;
}

void Display(Queue q) {
    if (q.front == q.rear) {
        cout << "Queue is empty!" << endl;
    } else {
        for (int i = q.front+1; i <= q.rear; i++)
        {
            cout << q.Q[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    struct Queue q;
    Create(&q);
    Display(q);
    Enqueue(&q, 2);
    Enqueue(&q, 3);
    Enqueue(&q, 5);
    Enqueue(&q, 7);
    Display(q);
    Dequeue(&q);
    Dequeue(&q);
    Display(q);
    return 0;
}