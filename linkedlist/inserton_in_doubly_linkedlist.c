#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

void traversal(struct Node *nodes){ //this will take head a argument
    while(nodes != NULL){
        printf("%d ",nodes->data);
        nodes = nodes->next;
    }
}

void traversalReverse(struct Node *nodes){ //this will take last element a argument
    while(nodes != NULL){
        printf("%d ",nodes->data);
        nodes = nodes->prev;
    }
}

//////////////////////case 1:insert head///////////////////////////////////
struct Node *insertfirstElement(struct Node *head,int data){
    struct Node *newHead = (struct Node*)malloc(sizeof(struct Node));
    newHead->data = data;
    newHead->prev = NULL;
    newHead->next = head;
    head = newHead;

    return head;
}


//////////////////////case 2:insert between///////////////////////////////////
struct Node *insertBetween(struct Node *head,int data,int index){

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while(i != index-1){
        p = p->next;
        i++;
    }
    newNode->next = p->next;
    p->next = newNode;
    newNode->prev = p;
    newNode->data = data;

    return head;
}

//////////////////////case 3:insert last Node///////////////////////////////////
struct Node *insertLastNode(struct Node *head,int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;

    newNode->data = data;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = newNode;
    newNode->next = NULL;
    newNode->prev = p;

    return head;
}

int main(){

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 31;
    head->prev = NULL;
    head->next = second;

    second->data = 32;
    second->prev = head;
    second->next = third;

    third->data = 33;
    third->prev = second;
    third->next = fourth;

    fourth->data = 34;
    fourth->prev = third;
    fourth->next = NULL;

    printf("Before insertion\n");
    traversal(head);
    printf("\n");

    //head = insertfirstElement(head,30);
    //head = insertBetween(head,35,2);
    head = insertLastNode(head,40);

    printf("\nAfter insertion\n");
    traversal(head);
    printf("\n");
    traversalReverse(fourth);
    
   

    return 0;
}