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
    Queue q;
}Stack;

void initStack(Stack* stack){
    initQueue(&stack->q);
}

void push(Stack* stack,int value){
    enqueue(&stack->q,value);
    int n=stack->q.size;
    for(int i=1;i<n;i++){
        int frontValue=dequeue(&stack->q);
        enqueue(&stack->q,frontValue);
    }
}

int pop(Stack* stack){
    return dequeue(&stack->q);
}

int peekStack(Stack* stack){
    return peek(&stack->q);
}

int isStackEmpty(Stack* stack){
    return isEmpty(&stack->q);
}

int stackSize(Stack* stack){
    return size(&stack->q);
}

int main(){
    Stack stack;
    initStack(&stack);
    push(&stack,10);
    push(&stack,20);
    push(&stack,30);
    printf("Top element: %d\n",peekStack(&stack));
    printf("Stack size: %d\n",stackSize(&stack));
    printf("Popped one Element: %d\n",pop(&stack));
    printf("Stack size after popping: %d\n",stackSize(&stack));
    printf("Top element after popping: %d\n",peekStack(&stack));
    return 0;
}
