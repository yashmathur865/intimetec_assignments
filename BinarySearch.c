#include<stdio.h>
#include<stdlib.h>

int BinarysearchX(int *arr,int n,int x){
    int low=0,high=n-1,mid;
    while(low<=high){
        mid=low+(high-low)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]>x){
            high = mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

int main(){
    int n,pos,x;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));
    printf("Enter %d elements\n",n);
    for(int i=0;i<n;i++){
         scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d",&x);

    pos=BinarysearchX(arr,n,x);
    if(pos==-1){
        printf("%d is not found in the array\n",x);
    }
    else{
        printf("%d is found in the array at position %d\n",x,pos+1);
    }
    free(arr);
    return 0;
}