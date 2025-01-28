#include <stdio.h>

int partition(int arr[], int l, int h)
{
    int pivot=arr[l];
    int i=l-1,j=h+1;

    while(1){
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j)return j;

        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}

void quickSort(int arr[],int l,int h){
    if(l<h){
        int p=partition(arr,l,h);
        quickSort(arr,l,p);
        quickSort(arr,p+1,h);
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

    quickSort(arr,0,size-1);
    printf("Array After Sorting\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}