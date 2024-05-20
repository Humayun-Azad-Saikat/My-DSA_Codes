#include<stdio.h>
#include<stdlib.h>

//stack using array

struct stack{

    int size; //this will be stack size
    int top; //top value will be -1 by default(if the stack is empty)
    int *arr; //we will request array memory form heap

};

int isEmpty(struct stack *ptr){ //this fuction will take a struct pointer as an argument
    if(ptr->top == -1){
        return 1; //1 means true(the stack is empty)
    }

    return 0; //0 means false(stack is not empty)
}

int isFull(struct stack *ptr){ //this fuction will take a struct pointer as an argument

    if (ptr->top == ptr->size-1){
        return 1; //1 means true(the stack is full)
    }
    return 0; //0 means false(stack is not full)
    
}

int main(){

    struct stack *s;

    s = (struct stack*)malloc(sizeof(struct stack));

    s->top = -1;
    s->size = 3;
    s->arr = (int*)malloc(s->size * sizeof(int));


//pushing elemnts mannualy in stack to check isEmpty function
    // s->arr[0] =7;
    // s->top++;


//pushing element mannualy in stack to check is full function
    s->arr[0] = 7;
    s->top++;
    s->arr[1] = 8;
    s->top++;
    s->arr[2] = 9;
    s->top++;


    //checking if stack is empty
    if(isEmpty(s)){
        printf("stack is empty");
    }else{
        printf("stack is not empty");
    }

    printf("\n");
    //checking if stack is full
    if(isFull(s)){
        printf("stack is full");
    }else{
        printf("stack is not full");
    }

    return 0;
}