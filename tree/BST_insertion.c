#include<stdio.h>
#include<stdlib.h>

struct Node{

    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data){

    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void insert_BST(struct Node *node,int data){

    struct Node *root = NULL;
    while(node != NULL){

        root = node;
        if(data == node->data){
            return;
        }
        else if(data < node->data){
            node = node->left;
        }
        else if(data > node->data){
            node = node->right;
        }
    }
    struct Node *newNode = createNode(data);
    if(data < root->data){
        root->left = newNode;
    }
    else if(data > root->data){
        root->right = newNode;
    }
}

void inOrder(struct Node *node){

    if(node != NULL){

        inOrder(node->left);
        printf("%d ",node->data);
        inOrder(node->right);
    }
}


int main(){

    struct Node *root,*n1,*n2,*c1,*c2;

    root = createNode(7);
    n1 = createNode(5);
    n2 = createNode(8);
    c1 = createNode(4);
    c2 = createNode(6);

    //linkup
    root->left = n1;
    root->right = n2;

    n1->left = c1;
    n1->right = c2;
    
    inOrder(root);
    insert_BST(root,10);
    printf("\n");
    inOrder(root);

    return 0;
}

/*

     7 
    /\
   5  8
  /\
 4  6

*/