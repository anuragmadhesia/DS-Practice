#include<stdio.h>
#include<conio.h>

int arr[10];
int size=sizeof(arr)/sizeof(int),front=-1,rear=-1;

void isFull(){
    if(front==(rear+1)%size){
        printf("queue is full\n");
    }
    else{
        printf("queue has %d space available",size-rear-1);
    }
}

void isEmpty(){
    if(front==-1){
        printf("queue is empty\n");
    }
    else{
        printf("queue is not empty");
    }
}

void getFront(){
    if(front==-1){
        printf("queue is empty\n");
    }
    else{
        printf("%d\n",arr[front]);
    }
    return ;
}

void enqueue(int ele){
    if(front==0 && rear==size-1){
        printf("queue is full, cannot insert element\n");
    }
    else{
        if(front==-1)front++;
        rear=(rear+1)%size;
        arr[rear]=ele;
    }
    return;
}

void dequeue(){
    if(front==-1){
        printf("queue is empty, cannot delete element\n");
    }
    else{
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%size;
        }
    }
    return;
}

void print(){
    if(front==-1){
        printf("queue is empty\n");
    }
    else{
        for (int i = front; i <= rear; i++)
        {
            printf("%d->",arr[i]);
        }
        printf("\n");
    }
    return ;
}
void menu(){
    printf("\n1 to enqueue\n2 to dequeue\n3 to check is empty\n4 to check is full\n5 to get top\n6 to print\n7 to exit");
    return;
}
int main(){
    int val;
    char input;
    menu();
    while(input!='7'){
        printf("\nEnter Choice : ");
        input=getch();
        switch (input)
        {
            case '1':printf("Enter Value : ");scanf("%d",&val);enqueue(val);print();break;
            case '2':dequeue();print();break;
            case '3':isEmpty();break;
            case '4':isFull();break;
            case '5':getFront();break;
            case '6':print();break;
            case '7':break;
            default:printf("\nWrong input!");menu();break;
        }
    }
    return 0;
}