#include<stdio.h>
#include<stdlib.h>


/*
inserting nodes in a linked list
steps:
1.request a new node in memory from heap
2.now link the new node with linked list(we can return a head after finishing the operations)
*/

struct Node{

int data;
struct Node *link;

};

void traversal(struct Node *nodes){

while (nodes != NULL){
    
printf("%d ",nodes->data);
nodes = nodes->link;

}

}

struct Node *insertAtHead(struct Node *head,int data){//case 1

struct Node *newHead= (struct Node*)malloc(sizeof(struct Node)); //requesting memory for new head

newHead->data = data;
newHead->link = head;
head = newHead;
return head;

}

struct Node *insertBetween(struct Node *head ,int data,int index){//case 2
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));//requesting memory for new node
    struct Node *p = head;

    int i = 0;
    while (i != index-1){
        p = p->link;
        i++;
    }
    
    newNode->data = data;
    newNode->link = p->link;
    p->link = newNode;
    

    return head;

}

struct Node *insertAtTheEnd(struct Node *head,int data){//case 3
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));//requesting memory for new node
    struct Node *p = head;
    newNode->data = data;

    while(p->link != NULL){
        p = p->link;
    }
    p->link = newNode;
    newNode->link = NULL;

    return head;

}


struct Node *insertAfterANode(struct Node *head,struct Node *prevNode,int data){//case 4
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));//requesting memory for new node

    newNode->data = data;

    newNode->link = prevNode->link;
    prevNode->link = newNode;

    return head;

}


int main(){

struct Node *head;//31
struct Node *second;//32
struct Node *third;//33

head = (struct Node*)malloc(sizeof(struct Node));
second = (struct Node*)malloc(sizeof(struct Node));
third = (struct Node*)malloc(sizeof(struct Node));

head->data = 31;
head->link = second;

second->data = 32;
second->link = third;

third->data = 33;
third->link = NULL;


traversal(head);
head = insertAtHead(head,30);
//head = insertBetween(head,34,2);
//head = insertAtTheEnd(head,40);
//head = insertAfterANode(head,second,35);
printf("\n");
traversal(head);

    return 0;
}