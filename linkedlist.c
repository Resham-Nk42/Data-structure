#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* createNode(int data){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insertAtfirst(struct Node** head,int data){
    struct Node* newNode=createNode(data);
        newNode->next=*head;
        *head=newNode;
    
}

void insertAtend(struct Node** head,int data){
    struct Node* newNode=createNode(data);
if(*head == NULL){
    *head=newNode;
    return;
}
struct Node* temp=*head;
while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=newNode;
}

void insertAtposition(struct Node **head,int data,int position){
  struct Node*  newNode=createNode(data);
    if(position == 0){
        insertAtfirst(head,data);
        return;
    }
  
    struct Node* temp=*head;

    for(int i=0;temp->next!=0 && position-1;i++){
        temp=temp->next;
    }

    if (temp==NULL){
        printf("position out od range\n");
        free(newNode);
        return;
    }
    newNode->next=temp->next;
    temp=temp->next;

}

void print(struct Node* head){
    struct Node* temp=head;

    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");


}

void deleteFromFirst(struct Node** head) {
if (*head == NULL) {
printf("List is empty\n");
return;
}
struct Node* temp = *head;
*head = temp->next;
free(temp);

}


void deleteFromEnd(struct Node** head) {
if (*head == NULL) {
printf("List is empty\n");
return;
}
struct Node* temp = *head;
if (temp->next == NULL) {
free(temp);
*head = NULL;
return;
}
while (temp->next->next != NULL) {
temp = temp->next;
}
free(temp->next);
temp->next = NULL;
}

void deleteAtPosition(struct Node** head, int position) {
if (*head == NULL) {
printf("List is empty\n");
return;
}
struct Node* temp = *head;
if (position == 0) {
deleteFromFirst(head);
return;
}
for (int i = 0; temp != NULL && i < position - 1; i++) {
temp = temp->next;

}
if (temp == NULL || temp->next == NULL) {
printf("Position out of range\n");
return;
}
struct Node* next = temp->next->next;
free(temp->next);
temp->next = next;
}



int main(){
    struct Node* head=NULL;

    insertAtfirst(&head,15);
    printf("after entering 15 to the list\n");
    print(head);

insertAtfirst(&head,11);
    printf("after entering 11 to the list\n");
    print(head);

insertAtfirst(&head,19);
    printf("after entering 19 to the list\n");
    print(head);

insertAtfirst(&head,17);
    printf("after entering 17 to the list\n");
    print(head);

insertAtend(&head,10);
    printf("after entering 10 to the end of list\n");
    print(head);

insertAtend(&head,13);
    printf("after entering 15 to the end of list\n");
    print(head);

insertAtposition(&head,11,2);
    printf("after entering 15 to the list\n");
    print(head);


deleteFromFirst(&head);
printf("Linked list after deleting the first node: \n");
print(head);


deleteFromEnd(&head);
printf("Linked list after deleting the last node: \n");
print(head);


deleteAtPosition(&head, 1);
printf("Linked list after deleting the node at position 1: \n");
print(head);

}

