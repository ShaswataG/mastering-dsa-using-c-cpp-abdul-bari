using namespace std;
#include<iostream>

struct Queue {
    int size, front, rear;
    int* Q;
};

void Create(struct Queue* q) {
    cout << "Enter size: ";
    cin >> q->size;
    q->Q = new int[q->size];
    q->front = q->rear = 0;
}

void Enqueue(struct Queue* q, int x) {
    if ((q->rear+1)%q->size == q->front) {
        cout << "Queue is full!" << endl;
    } else {
        q->rear = (q->rear+1)&q->size;
        q->Q[q->rear] = x;
    }
}

int Dequeue(struct Queue* q) {
    int x = -1;
    if (q->front == q->rear) {
        cout << "Queue is empty!" << endl;
    } else {
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q) {
    if (q.front == q.rear) cout << "Queue is empty!" << endl;
    else {
        for (int i = q.front+1; i <= q.rear; i = (i+1)%q.size)
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
    return 0;
}