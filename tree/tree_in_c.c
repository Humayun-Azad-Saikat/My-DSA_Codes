#include<stdio.h>
#include<stdlib.h>

struct Node{

    int data;
    struct Node *left,*right;
};

struct Node *createNode(int data){

    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

int main(){

    struct Node *root,*n1,*n2,*n3,*n4;

    root = createNode(7);
    n1 = createNode(2);
    n2 = createNode(1);
    n3 = createNode(0);
    n4 = createNode(4);

    //linking nodes
    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    n2->left = NULL;
    n2->right = NULL;


    return 0;
}