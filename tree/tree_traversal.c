#include<stdio.h>
#include<stdlib.h>

//it is a binary tree

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

void preOrder(struct Node *nodes){

    if(nodes != NULL){
        printf("%d ",nodes->data);
        preOrder(nodes->left);
        preOrder(nodes->right);
    }
}

void postOrder(struct Node *nodes){

    if(nodes != NULL){
        postOrder(nodes->left);
        postOrder(nodes->right);
        printf("%d ",nodes->data);
    }
}

void inOrder(struct Node *nodes){

    if(nodes != NULL){
        inOrder(nodes->left);
        printf("%d ",nodes->data);
        inOrder(nodes->right);
    }
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

    printf("preOrder:");
    preOrder(root);
    printf("\n");
    printf("postOrder:");
    postOrder(root);
    printf("\n");
    printf("inOrder:");
    inOrder(root);

    return 0;
}

/*

     7
    /\
   2  1
  /\
 0 4 

*/