#include<stdio.h>
#include<stdlib.h>

struct Node{

    int data;
    struct Node *next;

};

void traversal(struct Node *nodes){

    while(nodes != NULL){
        printf("%d ",nodes->data);
        nodes = nodes->next;
    }

}

///////////////////case 1:Delete first element///////////////////////////////////
struct Node *deleteHead(struct Node *head){
    struct Node *ptr = head;
    head = head->next;
    free(ptr);

return head;
}

/////////////////case 2:Delete an given index element////////////////////////////////////
struct Node *deleteAtIndex(struct Node *head,int index){

    struct Node *p = head;
    struct Node *q = head->next;

    int i = 0;
    while(i != index-1){
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);

    return head;

}

/////////////////case 3:Delete the last element////////////////////////////////////
struct Node *deleteLastElement(struct Node *head){

    struct Node *p = head;
    struct Node *q = head->next;

    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);

    return head;
}


/////////////////case 4:Delete Node with given value////////////////////////////////////
struct Node *deleteNodeWithGivenValue(struct Node *head,int value){

    struct Node *p = head;
    struct Node *q = head->next;

    while(value != q->data){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

    return head;

}



int main(){

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;


    //request memory form heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 30;
    head->next = second;

    second->data = 31;
    second->next = third;

    third->data = 32;
    third->next = fourth;

    fourth->data = 33;
    fourth->next = fifth;

    fifth->data = 34;
    fifth->next = NULL;

    traversal(head);
    printf("\n");
    //head = deleteHead(head);
    //head = deleteAtIndex(head,2);
    head = deleteLastElement(head);
    //head = deleteNodeWithGivenValue(head,33);
    traversal(head);


    return 0;
}