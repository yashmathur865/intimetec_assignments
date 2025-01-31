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
    stack->arr[++(stack->top)]=value;
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
    return stack->top+1;
}

struct Queue{
    struct Stack stack1;
    struct Stack stack2;
};

void initQueue(struct Queue* queue){
    initStack(&queue->stack1);
    initStack(&queue->stack2);
}

void enqueue(struct Queue* queue, int value){
    push(&queue->stack1, value);
}

int dequeue(struct Queue* queue){
    if(isEmpty(&queue->stack1) && isEmpty(&queue->stack2)){
        printf("Queue is empty!\n");
        return -1;
    }
    if(isEmpty(&queue->stack2)){
        while (!isEmpty(&queue->stack1)){
            push(&queue->stack2, pop(&queue->stack1));
        }
    }
    return pop(&queue->stack2);
}

int peekQueue(struct Queue* queue){
    if(isEmpty(&queue->stack1) && isEmpty(&queue->stack2)){
        printf("Queue is empty!\n");
        return -1;
    }
    if(isEmpty(&queue->stack2)){
        while(!isEmpty(&queue->stack1)){
            push(&queue->stack2, pop(&queue->stack1));
        }
    }
    return peek(&queue->stack2);
}

int isQueueEmpty(struct Queue* queue){
    return isEmpty(&queue->stack1) && isEmpty(&queue->stack2);
}

int queueSize(struct Queue* queue){
    return size(&queue->stack1) + size(&queue->stack2);
}

int main(){
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
