/*
 Title   : Implementation of Binary Search Tree ( insertion, deletion, traversal)
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *left, *right;
}tr;


tr *insert(tr *leaf, int x)
{
    if(leaf==NULL)
    {
        tr *newnode=(tr *)malloc(sizeof(tr));
        newnode->info=x;
        newnode->left=NULL;
        newnode->right=NULL;
        leaf=newnode;
    }
    else if(leaf->info>=x)
    {
        leaf->left=insert(leaf->left, x);
    }
    else
    {
        leaf->right=insert(leaf->right, x);
    }
    return leaf;
}

void inorder(tr *leaf)
{
    if(leaf!=NULL)
    {
        inorder(leaf->left);
        printf("%d ", leaf->info);
        inorder(leaf->right);
    }
}

void preorder(tr *leaf)
{
    if(leaf!=NULL)
    {
        printf("%d ", leaf->info);
        preorder(leaf->left);
        preorder(leaf->right);
    }
}

void postorder(tr *leaf)
{
    if(leaf!=NULL)
    {
        postorder(leaf->left);
        postorder(leaf->right);
        printf("%d ", leaf->info);
    }
}

struct queue{
    tr *a[10];
    int front, rear;
};

void init(struct queue *q){
    q->rear = q->front = -1;
}

void enqueue(struct queue *q, tr *leaf){
    if(q->rear == 9){
        printf("Queue overflow\n");
    }
    else{
        q->a[++q->rear] = leaf;
        if(q->front == -1){
            q->front = 0;
        }
    }
}

tr *dequeue(struct queue *q){
    tr *leaf;
    if(q->front == -1 || q->rear == -1 ){
        printf("List empty\n");
    }
    else if(q->front == q->rear){
        leaf = q->a[q->front];
        q->front = q->rear = -1;
    }
    else{
        leaf = q->a[q->front++];
    }
    return leaf;
}

void levelorder(tr *leaf){
    struct queue q;
    init(&q);
    tr *root;
    root = NULL;
    enqueue(&q, leaf);
    while(q.front != -1){
        root = dequeue(&q);
        printf("%d ", root->info);
        if(root->left != NULL){
            enqueue(&q, root->left);
        }
        if(root->right != NULL){
            enqueue(&q, root->right);
        }
    }
    printf("\n");
}

tr *trav_left(tr *leaf)
{
    if(leaf->left==NULL)
        return leaf;
    else
        return trav_left(leaf->left);
}


tr *delete(tr *leaf, int x)
{
    // base case
    if (leaf == NULL)
        return leaf;
    
    // If the x to be deleted is smaller than the root's x,
    // then it lies in left subtree
    else if (x < leaf->info)
        leaf->left = delete(leaf->left, x);
    
    // If the x to be deleted is greater than the root's x,
    // then it lies in right subtree
    else if (x > leaf->info)
        leaf->right = delete(leaf->right, x);
    
    // if x is same as root's x, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (leaf->left == NULL)
        {
            struct node *temp = leaf->right;
            free(leaf);
            return temp;
        }
        else if (leaf->right == NULL)
        {
            struct node *temp = leaf->left;
            free(leaf);
            return temp;
        }
        
        struct node* temp = trav_left(leaf->right);
        
        // Copy the inorder successor's content to this node
        leaf->info = temp->info;
        
        // Delete the inorder successor
        leaf->right = delete(leaf->right, temp->info);
    }
    return leaf;
}

int countTotal(tr *leaf)
{
    int c = 1;
    if(leaf == NULL){
        return 0;
    }
    else{
        return c + countTotal(leaf->left) + countTotal(leaf->right);
    }
}

int countInternal(tr *leaf)
{
    int c = 1;
    if(leaf->right == NULL && leaf->left == NULL){
        return 0;
    }
    else if(leaf->right == NULL){
        return c + countInternal(leaf->left);
    }
    else if(leaf->left == NULL){
        return c + countInternal(leaf->right);
    }
    else{
        return c + countInternal(leaf->left) + countInternal(leaf->right);
    }
}

int countExternal(tr *leaf)
{
    if(leaf->right == NULL && leaf->left == NULL){
        return 1;
    }
    else if(leaf->right == NULL){
        return countExternal(leaf->left);
    }
    else if(leaf->left == NULL){
        return countExternal(leaf->right);
    }
    else{
        return countExternal(leaf->left) + countExternal(leaf->right);
    }
}

int height(tr *leaf)
{
    if(leaf == NULL){
        return 0;
    }
    else{
        int ltree = height(leaf->left);
        int rtree = height(leaf->right);
        if(ltree > rtree){
            return ltree + 1;
        }
        else{
            return rtree + 1;
        }
    }
}

void main()
{
    tr *root;
    root = NULL;
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 3);
    root = delete(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = delete(root, 2);
    root = insert(root, 4);
    root = insert(root, 9);
    root = insert(root, 7);
    root = delete(root, 4);
    root = insert(root, 10);
    root = insert(root, 3);
    inorder(root);
    printf("Total number of nodes are %d\n", countTotal(root));
    printf("Total number of internal nodes are %d\n", countInternal(root));
    printf("Total number of external nodes are %d\n", countExternal(root));
    printf("Height of tree is %d\n", height(root));
    printf("Level order traversal is\n");
    levelorder(root);
}
