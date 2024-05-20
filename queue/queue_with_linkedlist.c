#include<stdio.h>
#include<stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;

struct Node{

    int data;
    struct Node *next;
};

int enqueue(int val){

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        return -1;
    }
    newNode->data = val;
    newNode->next = NULL;

    if(f == NULL){ //this is for:when we are enquing for the first time both f and r have to print the first elenment
        f = r = newNode;
    }
    else{ //and this condition will not true when first time enquing
        r->next = newNode;
        r = newNode;
        return val;
    }
    
}

int dequeue(){
    struct Node *ptr = f;

    if(f == NULL){
        return -1;
    }
    f = f->next;
    int val = f->data;
    free(ptr);
    return val;
}

void traversal(struct Node *ptr){
    
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

int main(){

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    dequeue();
    dequeue();

    traversal(f);


    return 0;
}