#include<stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void BubbleSort(int n,int arr[n]){
    for(int i=0;i<n-1;i++){
        int swapped=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                swapped=1;
            }
        }
        if(swapped==0){
            break;
        }
    }
}

int main(){
    int size;
    printf("Enter Size of Array\n");
    scanf("%d",&size);
    int arr[size];
    printf("Enter Elements\n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    BubbleSort(size,arr);
    printf("Array After Sorting\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}