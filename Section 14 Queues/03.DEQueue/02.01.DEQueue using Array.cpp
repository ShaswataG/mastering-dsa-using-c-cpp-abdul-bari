using namespace std;
#include<iostream>

struct DEQueue {
    int size, front, rear, Q[];
};

void Create(DEQueue* q, int s = 6) {
    // cout << "Enter size: ";
    // cin >> q->size;
    q->size = s;
    q->Q[q->size];
    q->front = q->rear = -1;
}

void FrontEnqueue(DEQueue* q, int x) {
    if (q->front < 0) {
        cout << "Can't enqueue from front." << endl;
    } else {
        q->Q[q->front] = x;
        q->front--;
    }
}

int FrontDequeue(DEQueue* q) {
    int x = -1;
    if (q->front <= q->rear) {
        x= q->Q[q->front+1];
        q->front++;
    } else {
        cout << "Can't dequeue from front." << endl;
    }
    return x;
}

void RearEnqueue(DEQueue* q, int x) {
    if (q->rear >= q->size-1) {
        cout << "Can't enqueue from rear." << endl;
    } else {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int RearDequeue(DEQueue* q) {
    int x = -1;
    if (q->rear <= q->front) {
        cout << "Can't dequeue from rear." << endl;
    } else {
        x = q->Q[q->rear];
        q->rear--;
    }
    return x;
}

void Display(DEQueue q) {
    if (q.front >= q.rear) {
        cout << "Queue is empty." << endl;
    } else {
        for (int i = q.front+1; i <q.rear; i++) {
            cout << q.Q[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    DEQueue q;
    Create(&q);
    int choice, a, b;
    while (1) {
        cout << "Press 1 to enqueue from front." << endl;
        cout << "Press 2 to enqueue from rear." << endl;
        cout << "Press 3 to dequeue from front." << endl;
        cout << "Press 4 to dequeue from rear." << endl;
        cout << "Press 5 to dispkay queue." << endl;
        cout << "Press 6 to exit." << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter element you want to enter from front : ";
            cin >> a;
            FrontEnqueue(&q, a);
            break;
        case 2:
            cout << "Enter element you want to enter from rear : ";
            cin >> b;
            RearEnqueue(&q, a);
            break;
        case 3:
            FrontDequeue(&q);
            break;
        case 4:
            RearDequeue(&q);
            break;
        case 5:
            Display(q);
        default:
            exit(0);
            break;
        }
    }
    return 0;
}