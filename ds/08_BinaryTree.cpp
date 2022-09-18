#include<iostream>
#include<queue>

using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void levelOrder(struct Node* root){
    queue<struct Node*>q;
    q.push(root);
    while (q.empty()==0)
    {
        struct Node* temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
    return;
}

void inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    return;
}
void preorder(struct Node* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    return;
}
void postorder(struct Node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
    return;
}
int main(){
    struct Node* root;
    root=createNode(3);
    root->left=createNode(6);
    root->right=createNode(45);
    root->left->left=createNode(16);
    root->left->right=createNode(4);
    root->left->right->left=createNode(14);
    root->left->right->right=createNode(1);
    root->right->right=createNode(25);
    root->right->right->left=createNode(85);

    cout<<"LevelOrder : ";
    levelOrder(root);

    cout<<"\nIn-Order : ";
    inorder(root);
    cout<<"\nPre-Order : ";
    preorder(root);
    cout<<"\nPost-Order : ";
    postorder(root);

    return 0;

         /*         3
                 /    \
                6     45
               / \      \
             16   4      25
                /   \   /
               14   1  85
        */
}