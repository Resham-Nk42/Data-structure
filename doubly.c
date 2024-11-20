#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

void insertatleft(struct Node** head, int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=(*head);
    newNode->prev=NULL;

    if((*head)!=NULL){
        (*head)->prev=newNode;
    }
    (*head)=newNode;

}
 void deleteatbeg(struct Node** head){
    if(*head == NULL){
        printf("the list is empty");
        return;
    }
    struct Node* temp=*head;
    if((*head)!=NULL){
        (*head)->prev=NULL;
    }
    free(temp);
 }

 void deleteatpos(struct Node** head, int pos){
    if(*head == NULL){
        printf("the list is empty");
        return;
    }
    struct Node* temp=*head;
    if(pos == 1){
        deleteatbeg(head);
        return;
    }
    for(int i=1;temp!=NULL && i<pos;i++){
        temp=temp->next;
    }
    if(temp == NULL){
        printf("the given no is greater than the nodes");
        return;
    }
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    if(temp->prev!=NULL){
        temp->prev->next=temp->next;
    }
    free(temp);
 }

 void displaylist(struct Node* node){
    struct Node* last;
    while(node!=NULL){
        printf("%d->",node->data);
        last=node;
        node=node->next;
    }
    if(node== NULL){
        printf("NULL\n");
    }
 }

 int main(){
    struct Node* head= NULL;
     insertatleft(&head,1);
     insertatleft(&head,2);
     insertatleft(&head,3);
     insertatleft(&head,4);
     insertatleft(&head,5);
     insertatleft(&head,6);

     displaylist(head);

     deleteatpos(&head,3);
     displaylist(head);
 }
