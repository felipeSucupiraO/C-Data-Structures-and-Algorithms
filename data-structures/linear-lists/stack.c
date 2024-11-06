#include <stdio.h>
#include <stdlib.h>

struct {
    int top;
    int capacity;
    int *array;
} typedef Stack;

int *alocateArray(int size) {
    int *array = NULL;
    while (array == NULL) {
        array = (int*)malloc(size * sizeof(int));
    }
    return array;
}

Stack createStack(int capacity) {
    Stack stack;
    stack.top = -1;
    stack.capacity = capacity;
    stack.array = alocateArray(capacity);

    return stack;
}

int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int addedElement) {
    if (isFull(stack)) {
        return;
    }
    stack->array[++stack->top] = addedElement;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->array[stack->top--];
}

int peek(Stack *stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->array[stack->top];
}

int main() {
    return 0;
}