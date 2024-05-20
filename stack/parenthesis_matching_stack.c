#include<stdio.h>
#include<stdlib.h>

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

int push(struct stack *ptr,char val){
    if(isFull(ptr)){
        return 0;
    }
    ptr->top++;
    ptr->arr[ptr->top] = val;
    return 1;
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        return 0;
    }
    ptr->top--;
    return 1;
}

int parenthesisMatch(char *exp){

    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = 100;
    sp->arr = (char*)malloc(sp->size * sizeof(char));

    int i = 0;
    while(exp[i] != '\0'){

        if(exp[i] == '('){
            push(sp,exp[i]);
        }
        else if(exp[i] == ')'){
            if(isEmpty(sp)){
                return 0;
            }
            else{
            pop(sp);
            }
        }

        i++;
    }
    if(isEmpty(sp)){
        return 1;
    }
    return 0;

}

int main(){

    char *exp = "4x(6+2)";
    if(parenthesisMatch(exp)){
        printf("The expression is valid");
    }
    else{
       printf("The expression is not valid");
    }
    


    return 0;
}