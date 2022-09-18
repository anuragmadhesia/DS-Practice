#include<stdio.h>

void Merge(int arr[],int start,int mid,int end){
    int i=start;
    int j=mid+1;
    int k=0;
    int temp[end-start+1];

    while(i<=mid && j<=end){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=end){
        temp[k++]=arr[j++];
    }

    for(i=start,k=0;i<=end;i++,k++){
        arr[i]=temp[k];
    }
    return ;
}
void mergeSort(int arr[],int start,int end){
    if(start<end)
    {
        int mid=(start+end)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        Merge(arr,start,mid,end);
    }
}

int main(){
    int arr[]={23,44,6,2,99,7,22,11,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    int i;
    printf("Array Before Sorting : ");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    mergeSort(arr,0,size-1);
    printf("\nArray After Sorting : ");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}