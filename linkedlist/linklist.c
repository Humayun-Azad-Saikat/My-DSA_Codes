#include<stdio.h>
#include<stdlib.h>

/*this is a normal singly linked list.

this linked list's last node(tail) points NULL.

*/

struct Node{
    int data;
    struct Node *next;
};


void traversal(struct Node *nodes){
  
while (nodes != NULL){
    printf("%d\n",nodes->data);
    nodes = nodes->next;
}


}


int main(){

struct Node *head,*second,*third;

head = (struct Node*)malloc(sizeof(struct Node));
second = (struct Node*)malloc(sizeof(struct Node));
third = (struct Node*)malloc(sizeof(struct Node));

head->data = 1;
head->next = second;

second->data = 2;
second->next = third;

third->data = 3;
third->next = NULL;

traversal(head);


    return 0;
}