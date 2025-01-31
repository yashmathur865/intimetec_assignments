#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Queue{
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;
}Queue;

void initializeQueue(Queue *queue){
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

int isEmpty(Queue *queue){
    return queue->size==0;
}

int isFull(Queue *queue){
    return queue->size==MAX_SIZE;
}

void enqueue(Queue *queue, int value){
    if(isFull(queue)){
        printf("Queue overflow. Cannot enqueue %d\n",value);
        return;
    }
    queue->rear=(queue->rear+1)%MAX_SIZE;
    queue->arr[queue->rear] = value;
    queue->size++;
    printf("Enqueued %d\n",value);
}

int dequeue(Queue *queue){
    if(isEmpty(queue)){
        printf("Queue underflow.Cannot dequeue\n");
        return -1;
    }
    int dequeuedValue=queue->arr[queue->front];
    queue->front=(queue->front+1) % MAX_SIZE;
    queue->size--;
    return dequeuedValue;
}

int peek(Queue *queue){
    if (isEmpty(queue)){
        printf("Queue is empty.No element to peek\n");
        return -1;
    }
    return queue->arr[queue->front];
}

int size(Queue *queue){
    return queue->size;
}

int main(){
    Queue queue;
    initializeQueue(&queue);

    enqueue(&queue,10);
    enqueue(&queue,20);
    enqueue(&queue,30);

    printf("Front element is %d\n",peek(&queue));
    printf("Queue size is %d\n",size(&queue));

    printf("Dequeued element is %d\n",dequeue(&queue));
    printf("Dequeued element is %d\n",dequeue(&queue));

    if(isEmpty(&queue)){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue is not empty\n");
    }

    printf("Queue size is %d\n",size(&queue));

    return 0;
}
