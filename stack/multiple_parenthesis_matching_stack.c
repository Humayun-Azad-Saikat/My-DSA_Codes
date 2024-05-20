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
}

int opening_closing_match(char a,char b){
    if(a == '(' && b == ')' || a == '{' && b == '}'|| a == '[' && b == ']'){
        return 1;
    }
    return 0;
}

int multi_paranthesis_check(char *exp){
    
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = 100;
    sp->arr = (char*)malloc(sp->size * sizeof(char));

    int i = 0;
    while(exp[i] != '\0'){

        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(sp,exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            //checking stack is empty
            if(isEmpty(sp)){
                return 0;
            }
            //checking opening and closing brackets
            if(!opening_closing_match(sp->arr[sp->top],exp[i])){
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

    char *exp = "[a+b-{v*c/(x+y)}]";

    if(multi_paranthesis_check(exp)){
        printf("expression is valid");
    }
    else{
        printf("expression is not valid");
    }


    return 0;
}