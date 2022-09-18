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

struct Node* insertElement(struct Node* root,int val){
    if(root==NULL){// if the tree is empty
        struct Node* temp=createNode(val);
        return temp;
    }
    if(root->data>=val){// Value to be inserted is smaller or equal
        root->left=insertElement(root->left,val);
    }
    else{// Value to be inserted is greater
        root->right=insertElement(root->right,val);
    }
    return root;
}

struct Node* inOrderSuccessor(struct Node* root){
    struct Node* ptr=root;
    while(ptr->left!=NULL){
        ptr=ptr->left;
    }
    return ptr;
}
struct Node* deleteNode(struct Node* root,int val){
    if(root->data>val){
        root->left=deleteNode(root->left,val);
    }
    else if(root->data<val){
        root->right=deleteNode(root->right,val);
    }
    else{
        if(root->right==NULL && root->left==NULL){// No child
            free(root);
            return NULL;
        }
        else if(root->right==NULL){// left child
            struct Node* temp=root->left;
            free(root);
            return temp;
        }
        else if(root->right==NULL){// right child
            struct Node* temp=root->right;
            free(root);
            return temp;
        }
        else{
            struct Node* temp=inOrderSuccessor(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
    }
    return root;
}

void searchInBST(struct Node* root,int val){
    if(root==NULL){
        cout<<"\nElement "<<val<<" Not Found!";
    }
    else if(root->data==val){
        cout<<"\nElement "<<val<<" is Present";
    }
    else if(root->data>val){
        searchInBST(root->left,val);
    }
    else{
        searchInBST(root->right,val);
    }
    return;
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
    struct Node* root=NULL;
    root=insertElement(root,10);
    root=insertElement(root,15);
    root=insertElement(root,6);
    root=insertElement(root,1);
    root=insertElement(root,8);
    root=insertElement(root,7);
    root=insertElement(root,9);
    root=insertElement(root,25);
    root=insertElement(root,18);

    cout<<"\nLevelOrder : ";levelOrder(root);
    cout<<"\nIn-order : ";inorder(root);
    cout<<"\nPre-order : ";preorder(root);
    cout<<"\nPost-order : ";postorder(root);
    searchInBST(root,25);
    searchInBST(root,245);

    deleteNode(root,1);
    cout<<"\nLevelOrder : ";levelOrder(root);
    deleteNode(root,25);
    cout<<"\nLevelOrder : ";levelOrder(root);
    return 0;

         /*        10
                 /    \
                6     15
               / \      \
             1   8      25
                /  \   /
               7   9  18
        */
}