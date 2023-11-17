#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front, * rear;
};

void enqueue(struct Queue* q, int x) {
    struct Node* t = (struct Node*) malloc(sizeof(struct Node));
    if (!t) {
        printf("Queue is full.\n");
        return;
    }
    t->data = x;
    t->next = NULL;
    if (!q->front) {
        q->front = q->rear = t;
    } else {
        q->rear->next = t;
        q->rear = t;
    }
}

int dequeue(struct Queue* q) {
    int x = -1;
    if (!q->front) return -1;
    struct Node* t;
    t = q->front;
    x = t->data;
    q->front = q->front->next;
    free(t);
    return x;
}

int empty(struct Queue q) {
    if (!q.front) return 1;
    return 0;
}

int full(struct Queue q) {
    struct Node* t = (struct Node*) malloc(sizeof(struct Node));
    if (!t) return 1;
    return 0;
}

void display(struct Queue q) {
    if (!q.front) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue is : ");
    struct Node* p = q.front;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void priorityEnqueue(struct Queue* q, int x) {
    struct Node* p = q->front;
    struct Node* r = NULL;
    struct Node* t = (struct Node*) malloc(sizeof(struct Node));
    t->data = x;
    if (!q->front) {
        q->front = q->rear = t;
        t->next = NULL;
    } else {
        while (p && x > p->data) {
            r = p;
            p = p->next;
        }
        if (p == q->front) {
            t->next = p;
            q->front = t;
        }
        if (r) t->next = r->next;
        if (r) r->next = t;
        if (!p) q->rear = t;
    }
}

int main() {
    struct Queue q;
    priorityEnqueue(&q, 3);
    priorityEnqueue(&q, 1);
    priorityEnqueue(&q, 6);
    priorityEnqueue(&q, 2);
    priorityEnqueue(&q, 7);
    priorityEnqueue(&q, 9);
    priorityEnqueue(&q, 0);
    display(q);
    printf("Dequeued element is : %d\n", dequeue(&q));
    printf("Dequeued element is : %d\n", dequeue(&q));
    printf("Dequeued element is : %d\n", dequeue(&q));
    display(q);
    return 0;
}