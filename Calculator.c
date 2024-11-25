#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 300

//Stack for operators
char operatorStack[MAX];
int operatorTop = -1;

//Stack for evaluation
int operandStack[MAX];
int operandTop = -1;

void pushOperator(char op){
    operatorStack[++operatorTop]=op;
}

char popOperator(){
    return operatorStack[operatorTop--];
}

void pushOperand(int digit){
    operandStack[++operandTop]=digit;
}

int popOperand(){
    return operandStack[operandTop--];
}

//Assign precedence to operators
int precedence(char op){
    if(op=='+'||op=='-')return 1;
    if(op=='*'||op=='/')return 2;
    return 0;
}

//Check if character is an operator
int isOperator(char ch){
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/');
}

//Function to convert infix expression to postfix
int infixToPostfix(char infix[], char postfix[]){

    int i=0,j=0;
    //Firstly i expect an operand
    int expectingOperand=1;

    while(infix[i]!='\0'){

        if(infix[i]==' '){
            i++; //Ignore spaces
            continue;
        }

        if(isdigit(infix[i]) || (infix[i]=='-' && isdigit(infix[i+1]) && expectingOperand)){
            //Handling numbers and negative numbers
            //Consecutive operands
            if (!expectingOperand) return -1;

            int sign = 1;
            if (infix[i] == '-') {
                sign = -1;
                i++;
            }

            int num = 0;
            while(isdigit(infix[i])){

                num = num*10 + (infix[i++] - '0');

            }
            num *= sign;

            //Adding the number to postfix
            int temp = num;
            if (num < 0) {
                postfix[j++] ='-';
                temp = -temp;
            }
            // Converting this number to string in reverse order
            char buffer[20];
            int len = 0;
            do {
                buffer[len++]=(temp % 10)+'0';
                temp/=10;
            }while(temp > 0);

            //Appending reversed number to postfix
            for (int k=len-1;k>=0;k--){
                postfix[j++] = buffer[k];
            }

            //Adding space
            postfix[j++]=' ';

            // Now expecting an operator again
            expectingOperand=0;
        }

        else if(isOperator(infix[i])){
            //Handling operators
            //Consecutive operators or it is starting with an operator
            if(expectingOperand) return -1;

            while(operatorTop!=-1 && precedence(operatorStack[operatorTop])>=precedence(infix[i])) {

                postfix[j++] = popOperator();
                postfix[j++] = ' ';
            }

            pushOperator(infix[i]);
            i++;
            //After operator i want operand
            expectingOperand = 1;
        }
        else {
            return -1;
        }
    }
    //Expression is ending with an operator
    if(expectingOperand) return -1;

    while (operatorTop != -1) {
        postfix[j++] = popOperator();
        postfix[j++] = ' ';
    }
    postfix[j] = '\0';
    return 0; //Success
}


// Function to evaluate postfix expression
int evaluatePostfix(char postfix[], int *isError){
    int i = 0;
    while(postfix[i] != '\0'){
        if(isdigit(postfix[i]) || (postfix[i] == '-' && isdigit(postfix[i + 1]))){
            // Handle numbers and negative numbers
            int num = 0,sign = 1;
            if(postfix[i] =='-'){
                sign= -1;
                i++;
            }
            while(isdigit(postfix[i])){
                num= num * 10 +(postfix[i++] - '0');
            }
            pushOperand(sign*num);
        }
        else if(isOperator(postfix[i])){
            if(operandTop < 1){
                //Invalid postfix expression
                *isError = 1;
                return 0;
            }
            int b = popOperand();
            int a = popOperand();

            if (postfix[i] == '/' && b == 0){
                //Division by zero check
                *isError = 2;
                return 0;
            }

            switch (postfix[i]){
                case '+': pushOperand(a + b); break;
                case '-': pushOperand(a - b); break;
                case '*': pushOperand(a * b); break;
                case '/': pushOperand(a / b); break;
            }
            i++;
        }
        else{
            //Ignoring that one space
            i++;
        }
    }
    return popOperand();
}

int main() {

    char infix[MAX];
    char postfix[MAX];

    printf("Enter an expression to evaluate: ");

    if (fgets(infix, MAX, stdin)){
        infix[strcspn(infix, "\n")] = '\0'; // To remove newline character
    }

    // Checking if it is a blank string or not
    int blank = 1;
    for(int i = 0;infix[i] != '\0';i++){
        if (infix[i] != ' ') {
            blank = 0;
            break;
        }
    }

    if(blank){
        printf("Error: Blank string\n");
        return 0;
    }

    int result = infixToPostfix(infix, postfix);
    if(result==-1){
        printf("Error: Invalid expression\n");
        return 0;
    }

    printf("Postfix Expression: %s\n", postfix);

    int error = 0;
    result = evaluatePostfix(postfix, &error);

    if(error==1){
        printf("Error: Invalid postfix expression\n");
    }
    else if(error == 2){
        printf("Error: Division by zero\n");
    }
    else{
        printf("Result: %d\n", result);
    }

    return 0;
}