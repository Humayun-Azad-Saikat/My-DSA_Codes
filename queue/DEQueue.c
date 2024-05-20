#include<stdio.h>
#include<stdlib.h>

//the normal queue is FIFO mean First In First Out
//but DEQueue concept is not same. DEQueue is Double Ended Queue means it does not follow normal operaion of queue

struct DEQueue{

    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct DEQueue *dq){

    if(dq->f == dq->r){
        return 1;
    }
    return 0;
}

int isFull(struct DEQueue *dq){

    if(dq->r == dq->size-1){
        return 1;
    }
    return 0;
}

int enqueue_r(struct DEQueue *dq,int val){ // normal enqueue operation

    if(isFull(dq)){
        return -1;
    }
    dq->r++;
    dq->arr[dq->r] = val;
}

int dequeue_f(struct DEQueue *dq){ //normal dequeue operation

    if(isEmpty(dq)){
        return -1;
    }
    int val = dq->arr[dq->f+1];
    dq->f++;
    return val;
}


int enqueue_f(struct DEQueue *dq,int val){

    if(isFull(dq)){
        return -1;
    }
    dq->arr[dq->f] = val;
    dq->f--;
    return val;
}

int dequeue_r(struct DEQueue *dq){
    
    if(isEmpty(dq)){
        return -1;
    }
    int val = dq->arr[dq->r];
    dq->r--;
    return val;
}

void traversal(struct DEQueue *dq){

    for(int i = dq->f+1; i <= dq->r; i++){
        printf("%d ",dq->arr[i]);
    }
}

int main(){

    struct DEQueue *dq = (struct DEQueue*)malloc(sizeof(struct DEQueue));

    dq->size = 5;
    dq->f = dq->r = -1;
    dq->arr = (int*)malloc(dq->size * sizeof(int));

    enqueue_r(dq,1);
    enqueue_r(dq,2);
    enqueue_r(dq,3);

    dequeue_f(dq);

    enqueue_f(dq,7);
    enqueue_f(dq,8);
    enqueue_f(dq,9);

    dequeue_r(dq);
    dequeue_r(dq);

    traversal(dq);


    return 0;
}