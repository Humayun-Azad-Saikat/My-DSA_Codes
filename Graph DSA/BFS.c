#include<stdio.h>
#include<stdlib.h>

struct Queue{

    int f,r;
    int *arr;
    int size;

};

int isEmpty(struct Queue *q){

    if(q->r == q->f){
        return 1;
    }
    return 0;

}

int isFull(struct Queue *q){

    if(q->r == q->size-1){
        return 1;
    }
    return 0;
}

int enqueue(struct Queue *q,int data){

    if(!isFull(q)){
        q->r++;
        q->arr[q->r] = data;
        return data;
    }
}

int dequeue(struct Queue *q){

    int data;
    if(!isEmpty(q)){
        data = q->arr[q->f+1];
        q->f++;
    }
    return data;
}


int main(){

    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->f = q->r = -1;
    q->size = 100;
    q->arr = (int*)malloc(q->size *sizeof(int));



    //implementing bfs
    int node;
    int i = 0;//traverse strat from i node
    int visited[7] = {0,0,0,0,0,0,0};
    int graph[7][7] = {

      // 0 1 2 3 4 5 6 
        {0,1,1,1,0,0,0},//0 // adjecency matrix for graph connection representation
        {1,0,1,0,0,0,0},//1
        {1,1,0,1,1,0,0},//2
        {1,0,1,0,1,0,0},//3
        {0,0,1,1,0,1,1},//4
        {0,0,0,0,1,0,0},//5
        {0,0,0,0,1,0,0} //6
    };

    
    printf("%d ",i);
    visited[i] = 1;
    enqueue(q,i);//enqueue i for exploration

    while(!isEmpty(q)){
        node = dequeue(q);
        for(int j = 0; j < 7;j++){

            if(graph[node][j] == 1 && visited[j] == 0){
                printf("%d ",j);
                visited[j] = 1;
                enqueue(q,j);
            }
        }
    }

    




    return 0;

}
