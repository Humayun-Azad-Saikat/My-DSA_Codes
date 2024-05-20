#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int isEmpty(struct Node *top){
    if(top == NULL){
        return 1;
    }
    return 0;
}

int isFull(struct Node *top){
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));

    if(p == NULL){
        return 1;
    }
    return 0;
}

void traversal(struct Node *top){
    while(top != NULL){
        printf("%d ",top->data);
        top = top->next;
    }
}

struct Node *push(struct Node *top,int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(isFull(top)){
        printf("stack is full");
    }
    newNode->next = top;
    newNode->data = data;
    top = newNode;
    return top;
    
}

struct Node *pop(struct Node *top){
    if(isEmpty(top)){
       return top;
    }
    struct Node *q = top;
    top = top-> next;
    free(q);
    return top;

}

int main(){

    struct Node *top = NULL;

    printf("\nbefore any operation isEmpty:%d\n",isEmpty(top));
    printf("before any operation isFull:%d\n",isFull(top));

    traversal(top);

    top = push(top,1);
    top = push(top,2);
    top = push(top,3);
    top = push(top,4);
    top = push(top,5);

    top = pop(top);
    top = pop(top);

    printf("\n");
    traversal(top);

    printf("\n\nbefore any operation isEmpty:%d\n",isEmpty(top));
    printf("before any operation isFull:%d\n\n",isFull(top));


    return 0;
}