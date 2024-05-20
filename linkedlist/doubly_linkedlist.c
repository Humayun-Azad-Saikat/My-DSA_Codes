#include<stdio.h>
#include<stdlib.h>

//doubly linkedlist points both previous node and next node

struct Node{
    int data;
    struct Node *prev;//it will point the previous node
    struct Node *next;//it will point the next node
};


void traversal(struct Node *nodes){ //this function will take head as argument
    while(nodes != NULL){
        printf("%d ",nodes->data);
        nodes = nodes->next;
    }
}

void traversalReverse(struct Node *nodes){ //this function will take last element as argument
    while(nodes != NULL){
        printf("%d ",nodes->data);
        nodes = nodes->prev;
    }
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

    head->data = 30;
    head->prev = NULL;
    head->next = second;

    second->data = 31;
    second->prev = head;
    second->next = third;

    third->data = 32;
    third->prev = second;
    third->next = fourth;

    fourth->data = 33;
    fourth->prev = third;
    fourth->next = NULL;

    traversal(head);
    printf("\n");
    traversalReverse(fourth);

    return 0;
}