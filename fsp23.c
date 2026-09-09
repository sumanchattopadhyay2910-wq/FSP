// write a c program queue using array.
#include <stdio.h>
#include <stdlib.h>

#define MAX 32

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    return (q->rear == MAX - 1);
}

int isEmpty(Queue *q) {
    return (q->front == -1);
}

void enqueue(Queue *q, int num) {
    if (!isFull(q)) {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear++;
        q->data[q->rear] = num;
    }
}

int dequeue(Queue *q) {
    if (!isEmpty(q)) {
        int num = q->data[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
        return num;
    }
    return -1; // Return -1 if queue is empty
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Dequeued elements: ");
    while (!isEmpty(&q)) {
        printf("%d ", dequeue(&q));
    }
    printf("\n");

    return 0;
}
