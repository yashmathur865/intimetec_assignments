#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct{
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;
}Queue;

void initQueue(Queue* q){
    q->front=0;
    q->rear=-1;
    q->size=0;
}

int isEmpty(Queue* q){
    return q->size==0;
}

int isFull(Queue* q){
    return q->size==MAX_SIZE;
}

void enqueue(Queue* q,int value){
    if(isFull(q)){
        printf("Queue is full!\n");
        return;
    }
    q->rear=(q->rear+1)%MAX_SIZE;
    q->arr[q->rear]=value;
    q->size++;
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return -1;
    }
    int value=q->arr[q->front];
    q->front=(q->front+1)%MAX_SIZE;
    q->size--;
    return value;
}

int peek(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return -1;
    }
    return q->arr[q->front];
}

int size(Queue* q){
    return q->size;
}

typedef struct{
    Queue q1;
    Queue q2;
}Stack;

void initStack(Stack* stack){
    initQueue(&stack->q1);
    initQueue(&stack->q2);
}

void push(Stack* stack,int value){
    enqueue(&stack->q1,value);
    while(!isEmpty(&stack->q1)){
        int frontValue=dequeue(&stack->q1);
        enqueue(&stack->q2,frontValue);
    }
    Queue temp=stack->q1;
    stack->q1=stack->q2;
    stack->q2=temp;
}

int pop(Stack* stack){
    if(isEmpty(&stack->q1)){
        printf("Stack is empty!\n");
        return -1;
    }
    return dequeue(&stack->q1);
}

int peekStack(Stack* stack){
    return peek(&stack->q1);
}

int isStackEmpty(Stack* stack){
    return isEmpty(&stack->q1);
}

int stackSize(Stack* stack){
    return size(&stack->q1);
}

int main(){
    Stack stack;
    initStack(&stack);

    push(&stack,10);
    push(&stack,20);
    push(&stack,30);

    printf("Top element: %d\n",peekStack(&stack));
    printf("Stack size: %d\n",stackSize(&stack));
    printf("Popped: %d\n",pop(&stack));
    printf("Stack size after pop: %d\n",stackSize(&stack));
    printf("Top element after pop: %d\n",peekStack(&stack));

    return 0;
}
