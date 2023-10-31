using namespace std;
#include<iostream>

struct Node {
    int data;
    Node* next;
} * front = NULL, * rear = NULL;

void Enqueue(int x) {
    Node* t = new Node;
    if (t== NULL) {
        cout << "Queue is full!" << endl;
    } else {
        t->data = x;
        t->next = NULL;
        if (front == NULL) {
            front = rear = t;
        } else {
            rear->next = t;
            rear = t;
        }
    }
}

int Dequeue() {
    int x = -1;
    if (front == NULL) {
        cout << "Queue is empty!" << endl;
    } else {
        x = front->data;
        Node* t = front;
        front = front->next;
        delete t;
    }
    return x;
}

void Display() {
    Node* t = front;
    if (t == NULL) {
        cout << "Queue is empty!" << endl;
    } else {
        while (t != NULL) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
}

int FirstElement() {
    int x = -1;
    if (front == NULL) {
        return x;
    } else {
        return front->data;
    }
}

int LastElement() {
    if (front == NULL) return -1;
    else return rear->data;
}

int main() {
    int choice;
    int a;
    while(true) {
        cout << "Press 1 to enqueue." << endl;
        cout << "Press 2 to dequeue." << endl;
        cout << "Press 3 to display." << endl;
        cout << "Press 4 to view first element." << endl;
        cout << "Press 5 to view last element." << endl;
        cout << "Press 6 to exit." << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
            cout << "Enter element you want to enqueue: ";
            cin >> a;
            Enqueue(a);
            break;
            case 2:
            Dequeue();
            break;
            case 3:
            Display();
            break;
            case 4:
            cout << "First element in the queue is : " << FirstElement() << endl;
            break;
            case 5:
            cout << "Last element in the queue is : " << LastElement() << endl;
            break;
            default:
            exit(0);
            break;
        }
    }
    return 0;
}