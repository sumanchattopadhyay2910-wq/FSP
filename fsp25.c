// circular queue using array.
#include <stdio.h>
#define MAX 32

typedef struct {
    int data[MAX];
    int front;
    int rear;
} CircularQueue;

void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(CircularQueue *q) {
    return ((q->rear + 1) % MAX == q->front);
}

int isEmpty(CircularQueue *q) {
    return (q->front == -1);
}

void enqueue(CircularQueue *q, int num) {
    if (!isFull(q)) {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX;
        q->data[q->rear] = num;
    }
}

int dequeue(CircularQueue *q) {
    if (!isEmpty(q)) {
        int num = q->data[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;
        }
        return num;
    }
    return -1; // Return -1 if queue is empty
}