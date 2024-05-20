#include<stdio.h>
#include<stdlib.h>

struct Node{

int key;
struct Node *right;
struct Node *left;
int height;

};

struct Node *createNode(int key){

    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1; // the height of every created node is 1      

    return n;
}

int getHeight(struct Node *n){

    if(n == NULL){
        return 0;
    }
    return n->height;
}

int max(int a,int b){

    return (a>b)?a:b;
}

struct Node *rightRotation(struct Node *y){

    struct Node *x = y->left;
    struct Node *t2 = x->right;

    //perform rotation
    x->right = y;
    y->left = t2;

    x->height = 1+max(getHeight(x->left),getHeight(x->right));
    y->height = 1+max(getHeight(y->left),getHeight(y->right));

    return x; //now x is the root

}

struct Node *leftRotation(struct Node *x){

    struct Node *y = x->right;
    struct Node *t2 = y->left;

    //perform rotation
    y->left = x;
    x->right = t2;

    x->height = 1+max(getHeight(x->left),getHeight(x->right));
    y->height = 1+max(getHeight(y->left),getHeight(y->right));

    return y; //now y is the root

}

int getBalance(struct Node *n){

    if(n == NULL){
        return 0;
    }
    return (getHeight(n->left)-getHeight(n->right));
}

//this insertion is like BST insertion.but this tree balance it self after insertion
struct Node *insert(struct Node *node,int key){

    if(node == NULL){
        return createNode(key);
    }

    if(key < node->key){
        node->left = insert(node->left,key);
    }
    else if(key > node->key){
        node->right = insert(node->right,key);
    }
    else{
        return node; //duplicate key is not accepted
    }

    //if the tree is unbalanced

    int balance = getBalance(node);

    //LL case
    if(balance > 1 && key < node->left->key){
        return rightRotation(node);
    }
    //RR case
    if(balance < -1 && key > node->right->key){
        return leftRotation(node);
    }
    //RL case
    if(balance < -1 && key < node->left->key){
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }
    //LR case
    if(balance > 1 && key > node->right->key){
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }

    return node;

}

void preOrder(struct Node *node){

    if(node != NULL){
        printf("%d ",node->key);
        preOrder(node->left);
        preOrder(node->right);
    }
}


int main(){

    struct Node *root = NULL;


    // root = insert(root,7);
    // root = insert(root,5);
    // root = insert(root,3);
    // root = insert(root,6);
    // root = insert(root,8);

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    preOrder(root);
   


    return 0;
}


/*

y = 7
x = 5
t1 = 3
t2 = 6
t3 = 8

    7
   /\
  5  8
 /\
3  6

*/



