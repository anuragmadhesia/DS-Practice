#include<stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int start,int end){
    int pivot=arr[end];
    int i=0,pindex=start-1;
    for(i=start;i<end;i++)
    {
        if(arr[i]<=pivot)
        {
            pindex++;
            swap(&arr[i],&arr[pindex]);
        }
    }
    swap(&arr[end],&arr[pindex+1]);
    return pindex+1;
}
void quickSort(int arr[],int start,int end){
    if(start<end)
    {
        int pindex=partition(arr,start,end);
        quickSort(arr,start,pindex-1);
        quickSort(arr,pindex+1,end);
    }
}

int main(){
    int arr[]={23,22,44,6,2,99,7,22,11,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    int i;
    printf("Array Before Sorting : ");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    quickSort(arr,0,size-1);
    printf("\nArray After Sorting : ");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}