#include<conio.h>
#include<stdio.h>

int arr[10];
int size=sizeof(arr)/sizeof(int);
int top=-1;

void push(int element){
    if(top==size-1){
        printf("stack is full\n");
    }
    else{
        top++;
        arr[top]=element;
    }
    return ;
}

void pop(){
    if(top==-1){
        printf("Stack is empty/n");
    }
    else{
        top--;
    }
    return ;
}

void isEmpty(){
    if(top==-1){
        printf("stack is completly empty\n");
    }
    else{
        printf("stack has %d empty space\n",size-top-1);
    }
    return ;
}

void getTop(){
    if(top=-1){
        printf("stack is empty\n");
    }
    else{
        printf("%d\n",arr[top]);
    }
    return ;
}

void print(){
    if(top==-1){
        printf("stack is empty\n");
    }
    else{
        for (int i = 0; i <= top; i++)
        {
            printf("%d->",arr[i]);
        }
        printf("\n");
    }
    return ;
}

void menu(){
    printf("\n1 to push\n2 to pop\n3 to check is empty\n4 to get top\n5 to print\n6 to exit");
    return;
}
int main(){
    int val;
    char input;
    menu();
    while(input!='6'){
        printf("\nEnter Choice : ");
        input=getch();
        switch (input)
        {
            case '1':printf("Enter Value : ");scanf("%d",&val);push(val);print();break;
            case '2':pop();print();break;
            case '3':isEmpty();break;
            case '4':getTop();break;
            case '5':print();break;
            case '6':break;
            default:printf("\nWrong input!");menu();break;
        }
    }
    return 0;
}