#include<conio.h>
#include<stdio.h>

int binarySearch(int arr[],int size,int val){
    int beg=0,end,mid;
    end=size-1;
    while(end>=beg){
        mid=((beg+end)/2);
        if(arr[mid]==val){
            return mid;
        }
        else if(arr[mid]>val){
            end=mid-1;
        }
        else{
            beg=mid+1;
        }
    }
    return -1;
}

int main(){
    int arr[]={1,6,20,21,56,66,71,83,99,939};
    int size=sizeof(arr)/sizeof(arr[0]);
    int val,pos;
    char ch;
    while(ch!='y')
    {   printf("Enter Element to search :");scanf("%d",&val);
        pos=binarySearch(arr,size,val);
        if(pos!=-1)
            printf("%d is present at index %d\n",val,pos+1);
        else
            printf("%d is not present in array\n",val);
        ch=getch();
    }
    return 0;
}