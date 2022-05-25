#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}

int main(){/*
    //Constructing the root first node
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->left = NULL; //p is root node
    p->right =NULL;
    //Constructing the second node
    struct node *p1;
    p1 = (struct node *)malloc(sizeof(struct node));
    p1->left = NULL; //p is root node
    p1->right =NULL;
    //Constructing the third node
    struct node *p2;
    p2 = (struct node *)malloc(sizeof(struct node));
    p2->left = NULL; //p is root node
    p2->right =NULL;

    */

    struct node* p = createNode(2);
    struct node* p1 = createNode(1);
    struct node* p2 = createNode(4);
// Linking the root node with left and right children
    p->left = p1;
    p->right = p2;

    return 0;
}