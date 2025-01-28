#include<stdio.h>

void merge(int l,int m,int r,int arr[]){
    int n1=m-l+1;
    int n2=r-m;
    int left[n1];
    int right[n2];
    for(int i=0;i<n1;i++){
        left[i]=arr[l+i];
    }
    for(int j=0;j<n1;j++){
        right[j]=arr[m+1+j];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k++]=left[i++];
        }
        else{
            arr[k++]=right[j++];
        }
    }
    while(i<n1){
        arr[k++]=left[i++];
    }
    while(j<n2){
        arr[k++]=right[j++];
    }
}

void mergeSort(int l,int r,int arr[]){
    if(r>l){
        int m=(l+r)/2;
        mergeSort(l,m,arr);
        mergeSort(m+1,r,arr);
        merge(l,m,r,arr);
    }
}

int main(){
    int size;
    printf("Enter Size Of Array\n");
    scanf("%d",&size);
    int arr[size];
    printf("Enter Elements\n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    mergeSort(0,size-1,arr);
    printf("Array After Sorting\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}