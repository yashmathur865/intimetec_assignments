#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack{
    int arr[MAX_SIZE];
    int top;
};

void initStack(struct Stack* stack){
    stack->top = -1;
}

int isEmpty(struct Stack* stack){
    return stack->top == -1;
}

int isFull(struct Stack* stack){
    return stack->top == MAX_SIZE-1;
}

void push(struct Stack* stack, int value){
    if(isFull(stack)){
        printf("Stack is full!\n");
        return;
    }
    stack->arr[++(stack->top)] = value;
}

int pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->arr[(stack->top)--];
}

int peek(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->arr[stack->top];
}

int size(struct Stack* stack){
    return stack->top + 1;
}
struct Queue{
    struct Stack stack;
};

void initQueue(struct Queue* queue){
    initStack(&queue->stack);
}

void enqueue(struct Queue* queue, int value){
    push(&queue->stack, value);
}
int dequeue(struct Queue* queue){
    if(isEmpty(&queue->stack)){
        printf("Queue is empty!\n");
        return -1;
    }

    struct Stack tempStack;
    initStack(&tempStack);

    while (!isEmpty(&queue->stack)){
        push(&tempStack, pop(&queue->stack));
    }


    int frontElement = pop(&tempStack);
    while (!isEmpty(&tempStack)) {
        push(&queue->stack, pop(&tempStack));
    }

    return frontElement;
}

int peekQueue(struct Queue* queue){
    if (isEmpty(&queue->stack)){
        printf("Queue is empty!\n");
        return -1;
    }
    struct Stack tempStack;
    initStack(&tempStack);

    while (!isEmpty(&queue->stack)) {
        push(&tempStack, pop(&queue->stack));
    }

    int frontElement = peek(&tempStack);

    while (!isEmpty(&tempStack)){
        push(&queue->stack, pop(&tempStack));
    }

    return frontElement;
}

int isQueueEmpty(struct Queue* queue) {
    return isEmpty(&queue->stack);
}
int queueSize(struct Queue* queue){
    return size(&queue->stack);
}

int main() {
    struct Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element: %d\n", peekQueue(&queue));
    printf("Queue size: %d\n", queueSize(&queue));

    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Queue size after dequeue: %d\n", queueSize(&queue));

    printf("Front element after dequeue: %d\n", peekQueue(&queue));

    return 0;
}
