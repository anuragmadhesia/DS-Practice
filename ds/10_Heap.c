#include<stdio.h>
#include<stdlib.h>
// Code for building heap
void maxHeapify(int arr[],int i,int size){
    int largest=i;
    int child1=2*i+1;
    int child2=2*i+2;

    if(child1<size && arr[largest]<arr[child1]){
        largest=child1;
    }
    if(child2<size && arr[largest]<arr[child2]){
        largest=child2;
    }
    if(largest!=i){
        int temp=arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;
        maxHeapify(arr,largest,size);
    }
    return ;
}
void buildHeap(int arr[],int size){
    int i=0;
    for(i=size/2;i>=0;i--){
        maxHeapify(arr,i,size);
    }
    return ;
}
//code for inserting element to max heap
void heapify(int arr[],int i){
    int parent=(i-1)/2;
    if(parent>=0 && arr[parent]<arr[i]){
        int temp=arr[parent];
        arr[parent]=arr[i];
        arr[i]=temp;
        heapify(arr,parent);
    }
    return ;
}
void insert(int arr[],int i,int val){
    arr[i]=val;
    heapify(arr,i);
    return ;
}
// code to pop the top elememt
int pop(int arr[],int size){
    int val=arr[0];
    int temp=arr[size-1];
    arr[size-1]=arr[0];
    arr[0]=temp;
    size=size-1;
    maxHeapify(arr,0,size);
    return val;
}
int main(){
    int arr[15]={19,1,2,3,36,25,100,17,7};
    int size=9;

    buildHeap(arr,9);
    int i;
    for(i=0;i<9;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    insert(arr,size,102);
    printf("102 is inserted in the heap, Now heap is : ");
    size=size+1;
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    int val=pop(arr,size);
    printf("%d is poped from top of heap, Now heap is : ",val);
    size=size-1;
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}