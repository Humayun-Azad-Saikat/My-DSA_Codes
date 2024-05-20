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

struct Node *sreachTree(struct Node *nodes,int data){

    while(nodes != NULL){

        if(nodes->data == data){
            return nodes;
        }
        if(data < nodes->data){
           return sreachTree(nodes->left,data);
        }
        else{
           return sreachTree(nodes->right,data);
        }
    }
    return NULL;
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

    n2->left = NULL;
    n2->right = NULL;

    struct Node *se = sreachTree(root,50);

    if(se != NULL){
        printf("found:%d",se->data);
    }
    else{
        printf("not found");
    }
    


    return 0;
}

/*

     7 
    /\
   5  8
  /\
 4  6

*/