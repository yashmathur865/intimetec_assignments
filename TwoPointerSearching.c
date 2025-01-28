#include<stdio.h>

int twoPointerSearch(int n,int arr[n],int target){
    int left=0,right=n-1;

    while(left<=right){
        if(arr[left]==target){
            return left;
        }
        if(arr[right]==target){
            return right;
        }
        left++;
        right--;
    }
    return -1;
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
    position=twoPointerSearch(n,arr,target);
    if(position==-1){
        printf("The Element is not present in array\n");
    }
    else{
        printf("The Element is present at position %d",position+1);
    }
    return 0;
}