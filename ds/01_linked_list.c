#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* insertatbeg(struct node* head,int val){
    struct node* newNode=(struct node*)(malloc(sizeof(struct node)));
    newNode->next=NULL;
    newNode->data=val;
    if(head==NULL){
        head=newNode;
        return head;
    }
    else{
        newNode->next=head;
        head=newNode;
        return head;
    }
}

struct node* insertatend(struct node* head,int val){
    struct node* newNode=(struct node*)(malloc(sizeof(struct node)));
    newNode->data=val;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        return head;
    }
    struct node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

struct node* insertatnth(struct node* head,int pos,int val){
    struct node* ptr=head;
    struct node* newNode=(struct node*)(malloc(sizeof(struct node)));
    newNode->next=NULL;
    newNode->data=val;
    if(pos==1){
        if(head!=NULL){
            newNode->next=head;
        }
        head=newNode;
        return head;
    }
    int i;
    for (i = 0; i < pos-2; i++)
    {
        ptr=ptr->next;
    }
    newNode->next=ptr->next;
    ptr->next=newNode;
    return head;
}

struct node* deletenode(struct node* head,int pos){
    struct node* temp=head;
    if(pos==1){
        head=temp->next;
        free(temp);
        return head;
    }
    int i;
    for(i=0;i<pos-2;i++){
        temp=temp->next;
    }
    struct node* temp2=temp->next;
    temp->next=temp2->next;
    free(temp2);
    return head;
}

struct node* reverselist(struct node* head){
    struct node *curr,*prev,*temp;
    prev=NULL;
    curr=head;
    while(curr!=NULL){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    head=prev;
    return head;
}

/* Counts no. of nodes in linked list */
int getCount(struct node* head)
{
    int count = 0;  // Initialize count
    struct node* current = head;  // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void print(struct node* head){
    struct node* p=head;
    while(p!=NULL){
        printf("->%d",p->data);
        p=p->next;
    }
    printf("\n");
    return;
}

void printwithadress(struct node* head){
    struct node* p=head;
    while(p!=NULL){
        printf("\ndata : %d,address : %d",p->data,p->next);
        p=p->next;
    }
    printf("\n");
    return;
}

void menu(){
    printf("\n1 to insert at start\n2 to insert at end\n3 to insert at nth postion\n4 to delete at nth pos\n5 to reverse the list\n6 to display the list\n7 to display the list with address\n8 to exit");
    return;
}

int main(){
    int val,pos;
    char input;
    struct node* head=NULL;
    menu();
    while(input!='8'){
        printf("\nEnter Choice : ");
        input=getch();
        switch (input)
        {
            case '1':printf("Enter Value : ");scanf("%d",&val);head=insertatbeg(head,val);break;
            case '2':printf("Enter Value : ");scanf("%d",&val);head=insertatend(head,val);break;
            case '3':printf("Enter Value and Position: ");scanf("%d%d",&val,&pos);
                     if(getCount(head)<pos){
                         printf("\nPosition is invalid!");
                     }
                     else{
                         head=insertatnth(head,pos,val);
                     }
                     break;
            case '4':printf("Enter Position : ");scanf("%d",&pos);
                     if(getCount(head)<pos){
                         printf("\nNO node to delete!");
                     }
                     else{
                         head=deletenode(head,pos);
                     }
                     break;
            case '5':head=reverselist(head);printf("List after reverse : ");print(head);break;
            case '6':printf("List : ");print(head);break;
            case '7':printf("List : ");printwithadress(head);break;
            case '8':break;
            default:printf("\nWrong input!");menu();break;
        }
    }
    return 0;
}