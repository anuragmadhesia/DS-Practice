#include<stdio.h>

int linearSearch(int arr[],int size,int val){
    for(int i=0;i<size;i++){
        if(arr[i]==val){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[]={23,21,56,566,1,3,77,99};
    int size=sizeof(arr)/sizeof(int);
    int val,pos;
    scanf("%d",&val);
    pos=linearSearch(arr,size,val);
    if(pos!=-1)
        printf("%d is present at index %d\n",val,pos+1);
    else
        printf("%d is not present in array\n",val);
    return 0;
}