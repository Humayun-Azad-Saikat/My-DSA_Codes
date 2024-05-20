#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int size;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    return 0;
}

void push(struct stack *ptr,int val){
    if(isFull(ptr)){
        printf("\n\nStack overflowed! can not push %d\n\n",val);
    }else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

void pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("\n\nstack is empty! can not pop any value\n\n");
    }
    else{
       // int val = ptr->arr[ptr->top];
        ptr->top--;
    }
}


void peek(struct stack *ptr,int i){
    if(isEmpty(ptr) || ptr->top <= 0 || i >= ptr->size+1){
        printf("\n\nno such item to peek\n\n");
    }
    else{
        printf("\n\npeeked item:%d\n\n",ptr->arr[ptr->top-i+1]);
    }
}

void stackTraversal(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("\n\nstack is empty! no such element to print\n\n");
    }
    else{
        for(int i = 0;i <= ptr->top;i++){
            printf("%d ",ptr->arr[i]);
        }
    }
}


int main(){

    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
 
    s->top = -1;
    s->size = 5;
    s->arr = (int*)malloc(s->size * sizeof(int));
    
    //pop(s);
    //peek(s,1);
   

    printf("\n\nbefore any operation in stack isEmpty:%d\n",isEmpty(s));
    printf("before any operation in stack isFull:%d",isFull(s));

    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    //push(s,6);

    peek(s,1); //peeked item will be 5

    pop(s);//poped value = 5

    printf("\n\nafter push in stack isEmpty:%d\n",isEmpty(s));
    printf("after push in stack isFull:%d\n\n",isFull(s));

    printf("stack traverse:\n");
    stackTraversal(s);
   
    return 0;
}