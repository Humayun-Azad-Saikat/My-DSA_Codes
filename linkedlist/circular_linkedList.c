#include<stdio.h>
#include<stdlib.h>

/*

this is a circular linked list.
normal linked list's(singly LL) last node points Null,
but curcular linked list's last Node(tail) points it's head(not NULL);

*/

struct Node{
    int data;
    struct Node *next;
};


void traversal(struct Node *head){

    struct Node *ptr = head;//for this head will not lost

    do{

        printf("%d ",ptr->data);
        ptr = ptr->next;
        
    }while(ptr != head);

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
head->next = second;

second->data = 31;
second->next = third;

third->data = 32;
third->next = fourth;

fourth->data = 33;
fourth->next = head;

traversal(head);

    return 0;
}