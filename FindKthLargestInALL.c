#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* head=NULL;

Node* createNode(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory Allocation Failed\n");
        exit(1);
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insertAtEnd(int data){
    Node* newNode=createNode(data);
    if(head==NULL){
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void printList(){
    Node *curr = head;
    while(curr!=NULL){
        printf("%d -> ",curr->data);
        curr=curr->next;
    }
    printf("NULL\n");
}

void bubbleSort(){
    if(head==NULL || head->next==NULL){
        return;
    }
    Node* i;
    Node* j;
    for(i=head;i!=NULL;i=i->next){
        int swapped=0;
        for(j=head;j->next!=NULL;j=j->next){
            if(j->data>j->next->data){
                int temp=j->data;
                j->data=j->next->data;
                j->next->data=temp;
                swapped=1;
            }
        }
        if(swapped==0){
            break;
        }
    }
}

int findKthLargest(int k) {
    Node* front = head;
    Node* back = head;

    for(int i=0;i<k;i++){
        if(front==NULL){
            return -1;
        }
        front = front->next;
    }

    while(front!=NULL){
        front=front->next;
        back=back->next;
    }
    return back->data;
}

int main(){
    int value;
    char c;
    while(1){
        if(scanf("%d",&value)>0){
            insertAtEnd(value);
        }
        else{
            break;
        }
        c=getchar();
        if(c=='\n'){
            break;
        }
    }

    int k;
    printf("Enter the value of k\n");
    scanf("%d",&k);
    if(k<=0){
        printf("Please Enter valid value of k\n");
        return 1;
    }

    int kthLargest;
    bubbleSort();
    printf("Linked List After Sorting\n");
    printList();
    kthLargest=findKthLargest(k);
    if(kthLargest==-1){
        printf("value of k exceeds the length of linked list\n");
        return 1;
    }
    printf("The %d-th largest element is: %d\n", k, kthLargest);
    return 0;
}