#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void traversal(struct Node *head){

    struct Node *ptr = head;
    do{
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }while(ptr != head);

}


/////////////case 1 insrt at first(insert head)//////////////////////////////
struct Node *insertAtFirst(struct Node *head,int data){

    struct Node *newHead = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head->next;

    newHead->data = data;
    while(p->next != head){
        p = p->next;
    }
    p->next = newHead;
    newHead->next = head;
    head = newHead;
    return head;

}

/////////////case 2 insrt between(insert with given index)//////////////////////////////
struct Node *insertBetween(struct Node *head,int data,int index){

    struct Node *p = head;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    int i = 0;
    newNode->data = data;
    while(i != index-1){
        p = p->next;
        i++;
    }
    newNode->next = p->next;
    p->next = newNode;

    return head;

}

struct Node *insertLastNode(struct Node *head,int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head->next;

    newNode->data = data;
    while(p->next != head){
        p = p->next;
    }
    p->next = newNode;
    newNode->next = head;
    return head;
}

struct Node *insertAfterANode(struct Node *head,struct Node *prevNode,int data){

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    
    newNode->next = prevNode->next;
    prevNode->next = newNode;

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
    head->next = second;

    second->data = 32;
    second->next = third;

    third->data = 33;
    third->next = fourth;

    fourth->data = 34;
    fourth->next = head;

    traversal(head);
    //head = insertAtFirst(head,30);
    //head = insertBetween(head,40,3);
    //head = insertLastNode(head,50);
    head = insertAfterANode(head,third,35);
    printf("\n");
    traversal(head);

    return 0;
}
