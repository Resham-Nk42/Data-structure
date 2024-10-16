#include <stdio.h>
#define MAX 5

int queue[MAX];
int f = -1, r = -1;

void insert(int value){
if (r == MAX-1){
  printf("queue is overflow!! cannot insert the value%d\n",value);
return;
}
 if(f == -1)
    f=0;
 r++;
 queue[r]=value;
 printf("%d inserted into the value\n",value);
}

void delete(){
if(f == -1 || f > r){
    printf("queue is underflow, its empty\n");
    return;
}
printf("%d deleted from the queue\n",queue[f]);
f++;
if(f > r){
    f = r = -1;
}
}

void display(){
if(f == -1 || f > r){
    printf("queue is underflow, its empty\n");
    return;
}
printf("queue elements:\n");
for(int i=f; i<=r; i++){
    printf("%d",queue[i]);
}
printf("\n");
}


int main(){
int choice,value;
while(1){
    printf("queue operations:\n");
    printf("1.insertion\n");
    printf("2.deletion\n");
    printf("3.display\n");
    printf("4.delete\n");
    printf("enter choice:");
    scanf("%d\n",&choice);

    switch(choice){
case 1:
    printf("insert the value:");
    scanf("%d",&value);
    insert(value);
    break;

case 2:
    delete();
    break;

case 3:
    display();
    break;

case 4:
    printf("exiting....");
    return 0;

default:
    printf("invalid choice, enter correct choice\n");
    }
}
return 0;
}
