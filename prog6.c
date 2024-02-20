//Find the Winner of the Circular Game
#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
} Queue;

Queue *createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (int *)malloc(size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

void enqueue(Queue *queue, int value) {
    if ((queue->rear + 1) % queue->size == queue->front) {
        return; // Queue is full
    }
    if (queue->front == -1) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % queue->size;
    }
    queue->arr[queue->rear] = value;
}

int dequeue(Queue *queue) {
    if (queue->front == -1) {
        return -1; // Queue is empty
    }
    int value = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->size;
    }
    return value;
}

int findTheWinner(int n, int k) {
    Queue *queue = createQueue(n);
    for (int i = 1; i <= n; i++) {
        enqueue(queue, i);
    }
    while (queue->front != queue->rear) {
        int x = k;
        while (x > 1) {
            int r = dequeue(queue);
            enqueue(queue, r);
            x--;
        }
        dequeue(queue);
    }
    int winner = dequeue(queue);
    free(queue->arr);
    free(queue);
    return winner;
}
