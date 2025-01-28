#include<stdio.h>

void insertionSort(int n,int arr[n]){
    for(int i=0;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && key<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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
    insertionSort(size,arr);
    printf("Array After Sorting\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}