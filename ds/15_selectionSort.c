#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selectionSort(int arr[],int size){
    int i,j;
    int minIndex;
    for(i=0;i<size-1;i++){
        minIndex=i;
        for(j=i+1;j<size;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
            swap(&arr[i],&arr[minIndex]);
        }
    }
    return;
}

int main(){
    int arr[]={23,44,6,2,99,7,22,11,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    int i;
    printf("Array Before Sorting : ");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    selectionSort(arr,size);
    printf("\nArray After Sorting : ");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}