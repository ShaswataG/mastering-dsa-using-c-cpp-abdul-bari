using namespace std;
#include<iostream>

struct Queue {
    int* Q;
    int size;
    int rear= -1;;
};


/*
Increasing value, decreasing priority
*/
void Insert(Queue* q, int x) {
/*
TC = O(1)
*/

    if (q->rear == q->size-1) cout << "Queue is full." << endl;
    else {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int Delete(Queue* q) {
/*
n + n = 2n ~ n
TC = O(n)
*/
    int x;
    int min = 0;
    for (int i =  1; i < q->size; i++)
    {
        if (q->Q[i] < q->Q[min]) min = i;
    }
    x = q->Q[min];
    for (int i = min; i < q->size; i++)
    {
        q->Q[i] = q->Q[i+1];
    }
    return x;
}

void Display(Queue q) {
    for (int i = 0; i < q.size; i++)
    {
        cout << q.Q[i] << " ";
    }
    cout << endl;
}

int main() {
    Queue q;
    int a[] = {6, 8, 1, 9, 3, 5, 4, 11};
    q.Q = new int[8];
    for (int i = 0; i < 8; i++)
    {
        Insert(&q, a[i]);
    }
    Display(q);
    cout << "Dequeued element is : " << Delete(&q) << endl;
    Display(q);
    return 0;
}