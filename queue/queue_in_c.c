#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q){
    if(q->f == q->r){
        return 1;
    }
    return 0;
}

int isFull(struct queue *q){
    if(q->r == q->size-1){
        return 1;
    }
    return 0;
}

int enqueue(struct queue *q,int val){
    if(isFull(q)){
        return -1;
    }
    q->r++;
    q->arr[q->r] = val;
    return val;
}

int dequeue(struct queue *q){

    if(isEmpty(q)){
        return -1;
    }
    if(q->f == q->r){
        q->f = q->r = -1;
    }
    int val = q->arr[q->f+1];
    q->f++;
    return val; 
}

void traversal(struct queue *q){
    int i = 0;
    for(i = q->f+1;i <= q->r; i++){
        printf("%d ",q->arr[i]);
    }
}


int main(){

    struct queue *q = (struct queue*)malloc(sizeof(struct queue));

    q->size = 5;
    q->f = q->r = -1;
    q->arr = (int*)malloc(q->size * sizeof(int));

    printf("before any operation isEmpty:%d\n",isEmpty(q));
    printf("before any operation isFull:%d\n",isFull(q));

    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    traversal(q);

    printf("\nafter any operation isEmpty:%d\n",isEmpty(q));
    printf("after any operation isFull:%d\n",isFull(q));


    return 0;
}