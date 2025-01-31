#include <stdio.h>

typedef struct{
    int arr[1000];
    int top;
}Stack;

void initializeStack(Stack* stack){
    stack->top = -1;
}

void push(Stack* stack,int value){
    if(stack->top==1000-1){
        printf("Stack overflow.Cannot push Element\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top]=value;
    printf("Pushed %d to the stack\n", value);
}

int pop(Stack* stack){
    if(stack->top == -1){
        printf("Stack underflow.Cannot pop\n");
        return -1;
    }
    int poppedValue=stack->arr[stack->top];
    stack->top--;
    return poppedValue;
}

int peek(Stack* stack){
    if(stack->top== -1){
        printf("Stack is empty.No element present\n");
        return -1;
    }
    return stack->arr[stack->top];
}

int isEmpty(Stack* stack){
    return stack->top== -1;
}

int size(Stack* stack){
    return stack->top+1;
}

int main() {
    Stack stack;
    initializeStack(&stack);

    push(&stack,10);
    push(&stack,20);
    push(&stack,30);

    printf("Top element is %d\n", peek(&stack));
    printf("Stack size is %d\n", size(&stack));

    printf("Popped element is %d\n", pop(&stack));
    printf("Popped element is %d\n", pop(&stack));

    if(isEmpty(&stack)){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack is not empty\n");
    }

    printf("Stack size is %d\n",size(&stack));

    return 0;
}
