#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct{
    Node* front;
    Node* rear;
    int size;
}Queue;

void initQueue(Queue* q){
    q->front=NULL;
    q->rear=NULL;
    q->size=0;
}

int isEmpty(Queue* q){
    return q->size==0;
}

void enqueue(Queue* q,int value){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    if(q->rear==NULL){
        q->front=newNode;
        q->rear=newNode;
    }else{
        q->rear->next=newNode;
        q->rear=newNode;
    }
    q->size++;
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return -1;
    }
    Node* temp=q->front;
    int frontValue=temp->data;
    q->front=q->front->next;
    if(q->front==NULL){
        q->rear=NULL;
    }
    free(temp);
    q->size--;
    return frontValue;
}

int peek(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return -1;
    }
    return q->front->data;
}

int size(Queue* q){
    return q->size;
}

int main(){
    Queue q;
    initQueue(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    printf("Front element of queue: %d\n",peek(&q));
    printf("Queue size: %d\n",size(&q));
    printf("Dequeued one element: %d\n",dequeue(&q));
    printf("Queue size after dequeue: %d\n",size(&q));
    printf("Front element after dequeue: %d\n",peek(&q));
    return 0;
}
