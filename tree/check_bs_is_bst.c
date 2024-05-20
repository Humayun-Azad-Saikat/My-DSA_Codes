#include<stdio.h>
#include<stdlib.h>

//check is a Binary Tree(BS) is a Binary Search Tree(BST) or not.

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

void inOrderTraversal(struct Node *nodes){

    if(nodes != NULL){
        inOrderTraversal(nodes->left);
        printf("%d ",nodes->data);
        inOrderTraversal(nodes->right);
    }
}

/*

this function works as inOrder traversal.
it starts checking from left of the tree
and ends in the right of the tree
while traverse it checks the condition of bst that if the previous element is smaller or not form the 
current element.

*/
int bs_is_bst(struct Node *nodes){

    static struct Node *prev = NULL;
    if(nodes != NULL){

        if(!bs_is_bst(nodes->left)){
            return 0;
        }

        if(prev != NULL && prev->data >= nodes->data){
            return 0;
        }
        prev = nodes;
        return bs_is_bst(nodes->right);

    }
    return 1;
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

    inOrderTraversal(root);
    printf("\n");
    printf("%d",bs_is_bst(root));



    return 0;
}

/*

     7 
    /\
   5  8
  /\
 4  6

*/