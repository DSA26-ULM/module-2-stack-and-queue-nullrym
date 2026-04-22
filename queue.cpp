#include "queue.h"

void init(Queue* q) {
    q->front = q->data;
    q->rear = q->data - 1;
}

bool isEmpty(const Queue* q) {
    return q->front > q->rear;
}

bool isFull(const Queue* q) {
    return q->rear == q->data + MAX - 1;
}

void enqueue(Queue* q, int value) {
    if (!isFull(q)) {
        *(++q->rear) = value;
    }
}

void dequeue(Queue* q) {
    if (!isEmpty(q)) {
        q->front++;
    }
}

int front(const Queue* q) {
    if (!isEmpty(q)) {
        return *q->front;
    }
    return -1; // or handle error appropriately
}

int back(const Queue* q) {
    if (!isEmpty(q)) {
        return *q->rear;
    }
    return -1; // or handle error appropriately
}
