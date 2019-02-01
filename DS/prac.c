#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *left, *right;
}tr;

tr *insert(tr *leaf, int n){
    if(leaf == NULL){
        leaf = (tr *)malloc(sizeof(tr));
        leaf->info = n;
        leaf->right = leaf->left = NULL;
    }
    else if(n <= leaf->info){
        leaf->left = insert(leaf->left, n);
    }
    else{
        leaf->right = insert(leaf->right, n);
    }
    return leaf;
}

tr *trav_left(tr *leaf){
    if(leaf->left == NULL){
        return leaf;
    }
    else{
        return trav_left(leaf->left);
    }
}

tr *delete(tr *leaf, int x){
    if(leaf == NULL){
        printf("Node not found\n");
        return leaf;
    }
    else if(x <= leaf->info){
        leaf->left = delete(leaf->left, x);
    }
    else if(x > leaf->info){
        leaf->right = delete(leaf->right, x);
    }
    else{
        if(leaf->left == NULL){
            tr *temp = leaf->right;
            printf("Deleted info = %d\n", leaf->info);
            free(leaf);
            return temp;
        }
        else if(leaf->right == NULL){
            tr *temp = leaf->left;
            printf("Deleted info = %d\n", leaf->info);
            free(leaf);
            return temp;
        }
        
        tr *temp = trav_left(leaf->right);
        printf("Deleted info = %d\n", leaf->info);
        leaf->info = temp->info;
        leaf->right = delete(leaf->right, temp->info);
    }
    return leaf;
}

void inorder(tr *leaf){
    if(leaf != NULL){
        inorder(leaf->left);
        printf("%d ", leaf->info);
        inorder(leaf->right);
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
    printf("\n");
}
