#include<stdio.h>

int linearSearch(int n,int arr[n],int target){
    int index=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            index=i;
            break;
        }
    }
    return index;
}

int main(){
    int n;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the Element to be searched\n");
    int target;
    scanf("%d",&target);
    int position;
    position=linearSearch(n,arr,target);
    if(position==-1){
        printf("The Element is not present in array\n");
    }
    else{
        printf("The Element is present at position %d",position+1);
    }
    return 0;
}