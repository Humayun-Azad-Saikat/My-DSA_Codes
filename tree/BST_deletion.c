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

struct Node *inOrderPredisissor(struct Node *node){

    node = node->left;
    while(node->right != NULL){
        node = node->right;
    }
    return node;
}

struct Node *delete_BST(struct Node *node,int data){

    struct Node *ipre;

    if(node == NULL){
        return NULL;
    }

    if(node->left == NULL && node->right == NULL){
        free(node);
        return NULL;
    }

    //finding nodes
    if(data < node->data){
        node->left = delete_BST(node->left,data);
    }
    else if(data > node->data){
        node->right = delete_BST(node->right,data);
    }

    //deletion approach
    else{
        ipre = inOrderPredisissor(node);
        node->data = ipre->data;
        delete_BST(node->left,ipre->data);
    }
    return node;

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
    delete_BST(root,6);
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