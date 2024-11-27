#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*left,*right;
};

struct Node *newNode(int value){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=value;
    temp->left=temp->right=NULL;
    return temp;
}

struct Node *insertNode(struct Node *node, int value){
       if(node == NULL){
        return newNode(value);
       }
       if(value<node->data){
        node->left=insertNode(node->left,value);
       }
       if(value>node->data){
        node->right=insertNode(node->right,value);
       }
       return node;
}

void postord(struct Node *root){
if(root!=NULL){
    postord(root->left);
    postord(root->right);
    printf("%d ",root->data);
}
}

void inord(struct Node *root){
if(root!=NULL){
    inord(root->left);
    printf("%d ",root->data);
    inord(root->right);
}
}

void preord(struct Node *root){
if(root!=NULL){
    printf("%d ",root->data);
    preord(root->left);
    preord(root->right);
}
}

int main(){
    struct Node *root=NULL;
    root=insertNode(root,40);
    insertNode(root,50);
    insertNode(root,80);
    insertNode(root,30);
    insertNode(root,20);
    insertNode(root,90);
    insertNode(root,70);
    insertNode(root,10);
    insertNode(root,100);
    insertNode(root,60);
    printf("postorder\n");
    postord(root);
    printf("\n");

    printf("inorder\n");
    inord(root);
    printf("\n");

    printf("preorder\n");
    preord(root);
    printf("\n");
    return 0;
}