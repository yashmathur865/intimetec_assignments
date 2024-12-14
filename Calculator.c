//I am first converting the input string to postfix expression and then evaluating it.

#include <stdio.h>
#include <string.h>

#define MAX 300

char operatorStack[MAX];
int operatorTop=-1;


int operandStack[MAX];
int operandTop=-1;

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

int precedence(char op){
    if(op=='+'||op=='-')return 1;
    if(op=='*'||op=='/')return 2;
    return 0;
}

int isOperator(char ch){
    return (ch=='+'|| ch=='-'|| ch=='*'|| ch=='/');
}

int isDigit(char ch){
    return (ch>='0' && ch<='9');
}

int infixToPostfix(char infix[], char postfix[]){

    int i=0,j=0;
    int expectingOperand=1;

    while(infix[i]!='\0'){

        if(infix[i]==' '){
            i++;
            continue;
        }

        if(isDigit(infix[i]) || (infix[i]=='-' && isDigit(infix[i+1]) && expectingOperand)){
            if (!expectingOperand) return -1;

            int sign = 1;
            if (infix[i]=='-') {
                sign=-1;
                i++;
            }

            int num=0;
            while(isDigit(infix[i])){

                num=num*10+(infix[i++] -'0');

            }
            num *= sign;

            int temp=num;
            if (num < 0) {
                postfix[j++]='-';
                temp = -temp;
            }

            char buffer[20];
            int len = 0;
            do {
                buffer[len++]=(temp % 10)+'0';
                temp/=10;
            }while(temp > 0);


            for (int k=len-1;k>=0;k--){
                postfix[j++]=buffer[k];
            }


            postfix[j++]=' ';

            expectingOperand=0;
        }

        else if(isOperator(infix[i])){

            if(expectingOperand)return -1;

            while(operatorTop!=-1 && precedence(operatorStack[operatorTop])>=precedence(infix[i])) {

                postfix[j++] = popOperator();
                postfix[j++]=' ';
            }

            pushOperator(infix[i]);
            i++;

            expectingOperand=1;
        }
        else {
            return -1;
        }
    }

    if(expectingOperand) return -1;

    while (operatorTop != -1) {
        postfix[j++]=popOperator();
        postfix[j++]=' ';
    }
    postfix[j]='\0';
    return 0;
}



int evaluatePostfix(char postfix[], int *isError){
    int i = 0;
    while(postfix[i] != '\0'){
        if(isDigit(postfix[i]) || (postfix[i]=='-' && isDigit(postfix[i + 1]))){
            int num=0,sign=1;
            if(postfix[i]=='-'){
                sign= -1;
                i++;
            }
            while(isDigit(postfix[i])){
                num= num*10 +(postfix[i++] - '0');
            }
            pushOperand(sign*num);
        }
        else if(isOperator(postfix[i])){
            if(operandTop<1){

                *isError = 1;
                return 0;
            }
            int b=popOperand();
            int a=popOperand();

            if(postfix[i]=='/' && b==0){

                *isError=2;
                return 0;
            }

            switch(postfix[i]){
                case '+': pushOperand(a+b); break;
                case '-': pushOperand(a-b); break;
                case '*': pushOperand(a*b); break;
                case '/': pushOperand(a/b); break;
            }
            i++;
        }
        else{
            i++;
        }
    }
    return popOperand();
}

int main(){

    char infix[MAX];
    char postfix[MAX];

    printf("Enter an expression to evaluate: ");

    if(fgets(infix, MAX, stdin)){
        infix[strcspn(infix, "\n")]='\0';
    }

    int blank=1;
    for(int i=0;infix[i] != '\0';i++){
        if(infix[i] != ' ') {
            blank=0;
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

    int error=0;
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