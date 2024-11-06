#include <stdio.h>
#include <stdlib.h>

struct {
    int front;
    int back;
    int size;
    int capacity;
    int *array;
} typedef Queue;

int *alocateArray(int size) {
    int *array = NULL;
    while (array == NULL) {
        array = (int*)malloc(size * sizeof(int));
    }
    return array;
}

Queue createQueue(int capacity) {
    Queue queue;
    queue.capacity = capacity;
    queue.array = alocateArray(capacity);
    queue.size = 0;
    queue.front = 0;
    queue.back = capacity - 1;

    return queue;
}

int isFull(Queue *queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue *queue) {
    return (queue->size == 0);
}

void enqueue(Queue *queue, int addedElement) {
    if (isFull(queue)) {
        return;
    }
    queue->back = (queue->back + 1) % queue->capacity;
    queue->array[queue->back] = addedElement;
    queue->size++;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        return NULL;
    }
    int deletedElement = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return deletedElement;
}

int front(Queue *queue) {
    if (isEmpty(queue)) {
        return NULL;
    }
    return queue->array[queue->front];
}

int back(Queue *queue) {
    if (isEmpty(queue)) {
        return NULL;
    }
    return queue->array[queue->back];
}

int main() {
    return 0;
}