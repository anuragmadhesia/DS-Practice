#include<stdio.h>

void insertionSort(int arr[],int size){
    int i,j;
    for(i=1;i<size;i++){
        int temp=arr[i];
        for(j=i;j>=1;j--){
            if(arr[j-1]>temp){
                arr[j]=arr[j-1];
            }
            else
            {
                break;
            }
        }
        arr[j]=temp;
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
    insertionSort(arr,size);
    printf("\nArray After Sorting : ");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}