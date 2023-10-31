using namespace std;
#include<iostream>

template<class T>
class Queue {
    private:
        int size, front, rear;
        int* Q;
    public:
        Queue();
        Queue(int);
        void Enqueue(int);
        T Dequeue();
        void Display();
};

template<class T>
Queue<T>::Queue() {
    size = 10;
    Q = new int[size];
    front = -1;
    rear = -1;
}

template<class T>
Queue<T>::Queue(int size) {
    this->size = size;
    Q = new int[this->size];
    front = -1;
    rear = -1;
}

template<class T>
void Queue<T>::Enqueue(int x) {
    if (rear == size-1) {
        cout << "Queue is full!" << endl;
        return;
    } else {
        rear++;
        Q[rear] = x;
    }
}

template<class T>
T Queue<T>::Dequeue() {
    T x;
    if (front == rear) {
        x = -1;
        cout << "Queue is empty!" << endl;
    } else {
        front++;
        x = Q[front];
    }
    return x;
}

template<class T>
void Queue<T>::Display() {
    if (front == rear) {
        cout << "Queue is empty!" << endl;
        return;
    } else {
        cout << "Elements are: ";
        for (int i = front+1; i <= rear; i++) {
           cout << Q[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int s = 7;
    int choice;
    int a, b;
    Queue<int> q(s);
    while (1) {
        cout << "Press 1 to enqueue." << endl << "Press 2 to dequeue." << endl << "Press 3 to display." << endl << "Press 4 to exit." << endl;
        cin >> choice;
        switch(choice)
        {
            case 1 :
            cout << "Enter element you want to enqueue: ";
            cin >> a;
            q.Enqueue(a);
            break;
            case 2 :
            b = q.Dequeue();
            if (b != -1)
                cout << "Element dequeued is: " << b << endl;
            break;
            case 3 :
            q.Display();
            break;
            default :
            exit(0);
            break;
        }
    }
    return 0;
}