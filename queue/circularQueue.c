#include<stdio.h>
#include<stdlib.h>

struct circularQueue{
    
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct circularQueue *q){
    if(q->f == q->r){
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue *q){
    if((q->r +1)%q->size == q->f){
        return 1;
    }
    return 0;
}

int enqueue(struct circularQueue *q,int val){
    if(isFull(q)){
        return -1;
    }
    q->r = (q->r+1)%q->size; //circular increment
    q->arr[q->r] = val;
    return val;
}

int dequeue(struct circularQueue *q){
    if(isEmpty(q)){
        return -1;
    }
    q->f = (q->f +1)%q->size; //circular increment
    int val = q->arr[q->f];
    return val;

}


void traverse(struct circularQueue *q){
    int i;
    for(i = q->f+1;i <= q->r;i++){
        printf("%d ",q->arr[i]);
    }
}

int main(){

    struct circularQueue *q = (struct circularQueue*)malloc(sizeof(struct circularQueue));
    q->f = q->r = 0;
    q->size = 5;
    q->arr = (int*)malloc(q->size * sizeof(int));

    printf("before any operation isEmpty:%d\n",isEmpty(q));
    printf("before any operation isFull:%d\n\n",isFull(q));

    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    traverse(q);

    printf("\n\nafter any operation isEmpty:%d\n",isEmpty(q));
    printf("after any operation isFull:%d\n\n",isFull(q));
    

    return 0;
}