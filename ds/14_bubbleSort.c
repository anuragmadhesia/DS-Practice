#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubbleSort(int arr[],int size){
    int i,j,swapped=0;
    for(i=0;i<size;i++){
        swapped=0;
        for(j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swapped=1;
                swap(&arr[j],&arr[j+1]);
            }
        }
        if(swapped==0){
            break;
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
    bubbleSort(arr,size);
    printf("\nArray After Sorting : ");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}