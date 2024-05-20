#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int top;
    int size;
    char *arr;
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

char push(struct stack *ptr,char val){
    if(isFull(ptr)){
        return '\0';
    }
    ptr->top++;
    ptr->arr[ptr->top] = val;
    return val;
}

char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        return '\0';
    }
    char val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
    
}

int operator(char infix){
    if(infix == '+' || infix == '-' || infix == '*' || infix == '/'){
        return 1;
    }
    return 0;
}

int presidence(char infix){
    if(infix == '*' || infix == '/'){
        return 3;
    }
    else if(infix == '+' || infix == '-'){
        return 2;
    }
    else{
        return 0;
    }
}

char *infixToPostfix(char *infix){

    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = 50;
    sp->arr = (char*)malloc(sp->size * sizeof(char));

    char *postfix = (char*)malloc((strlen(infix)+1) * sizeof(char));

    int i = 0;//for tracking infix
    int j = 0;//for tracking postfix
    while(infix[i] != '\0'){
        if(!operator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }
        if(presidence(infix[i]) > presidence(sp->arr[sp->top])){
            push(sp,infix[i]);
            i++;
        }
        else{
            postfix[j] = pop(sp);
            j++;
        }
    }
    while(!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;

}

int main(){

    char *infix = "x-y/z-k*d";
    printf("%s",infixToPostfix(infix));



    return 0;
}