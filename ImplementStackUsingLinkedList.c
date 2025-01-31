#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct Stack{
    Node *top;
    int size;
}Stack;

void initializeStack(Stack *stack){
    stack->top = NULL;
    stack->size = 0;
}

void push(Stack *stack, int value){
    Node *newNode=(Node *)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory allocation failed. Cannot push %d\n", value);
        return;
    }
    newNode->data=value;
    newNode->next=stack->top;
    stack->top=newNode;
    stack->size++;
    printf("Pushed %d onto the stack\n", value);
}

int pop(Stack *stack){
    if(stack->top==NULL){
        printf("Stack underflow. Cannot pop\n");
        return -1;
    }
    Node *temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return poppedValue;
}

int peek(Stack *stack){
    if(stack->top==NULL){
        printf("Stack is empty. No element to peek\n");
        return -1;
    }
    return stack->top->data;
}

int isEmpty(Stack *stack){
    return stack->top==NULL;
}

int size(Stack *stack){
    return stack->size;
}

int main(){
    Stack stack;
    initializeStack(&stack);

    push(&stack,10);
    push(&stack,20);
    push(&stack,30);

    printf("Top element is %d\n",peek(&stack));
    printf("Stack size is %d\n",size(&stack));

    printf("Popped element is %d\n",pop(&stack));
    printf("Popped element is %d\n",pop(&stack));

    if(isEmpty(&stack)){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack is not empty\n");
    }

    printf("Stack size is %d\n", size(&stack));

    return 0;
}
