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


void main()
{

    tr *root;
    root=NULL;
    int ch, n, x;
    do
    {
        printf("************Main Menu***************\n1.To insert element\n2.To delete element\n3.To print using inorder\n4.To print using preorder\n5.To print using postorder\n6.To exit\n***************************\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            {
                printf("Enter data to be stored\n");
                scanf("%d", &x);
                root=insert(root,x);
                break;
            }
            case 2:
            {
                printf("Enter data to be deleted\n");
                scanf("%d", &x);
                root=delete(root,x);
                break;
            }
                
            case 3:
            {
            	if (root == NULL)
            	{
            		printf("Tree is empty\n");
            		break;
            	}
            	else
                {
		        printf("Tree printed inorder is\n");
		        inorder(root);
		        printf("\n");
		        break;
                }
            }
                
            case 4:
            {
            	if (root == NULL)
            	{
            		printf("Tree is empty\n");
            		break;
            	}
            	else
                {
		        printf("Tree printed in preorder is\n");
		        preorder(root);
		        printf("\n");
		        break;
                }
            }
                
            case 5:
            {
            	if (root == NULL)
            	{
            		printf("Tree is empty\n");
            		break;
            	}
            	else
                {
		        printf("Tree printed in postorder is\n");
		        postorder(root);
		        printf("\n");
		        break;
                }
            }
       
            case 6:
            {
                printf("Program terminated, Thank You\n");
                break;
            }
            default:
            {
                printf("Invalid entry\n");
                break;
            }
        }
    }while(ch!=6);
}

/*
************Main Menu***************
1.To insert element
2.To delete element
3.To print using inorder
4.To print using preorder
5.To print using postorder
6.To exit
***************************
1
Enter data to be stored
5
************Main Menu***************
1.To insert element
2.To delete element
3.To print using inorder
4.To print using preorder
5.To print using postorder
6.To exit
***************************
1
Enter data to be stored
3
************Main Menu***************
1.To insert element
2.To delete element
3.To print using inorder
4.To print using preorder
5.To print using postorder
6.To exit
***************************
1
Enter data to be stored
4
************Main Menu***************
1.To insert element
2.To delete element
3.To print using inorder
4.To print using preorder
5.To print using postorder
6.To exit
***************************
1
Enter data to be stored
2
************Main Menu***************
1.To insert element
2.To delete element
3.To print using inorder
4.To print using preorder
5.To print using postorder
6.To exit
***************************
1
Enter data to be stored
6
************Main Menu***************
1.To insert element
2.To delete element
3.To print using inorder
4.To print using preorder
5.To print using postorder
6.To exit
***************************
1
Enter data to be stored
7
************Main Menu***************
1.To insert element
2.To delete element
3.To print using inorder
4.To print using preorder
5.To print using postorder
6.To exit
***************************
3
Tree printed inorder is
2 3 4 5 6 7 
************Main Menu***************
1.To insert element
2.To delete element
3.To print using inorder
4.To print using preorder
5.To print using postorder
6.To exit
***************************
4
Tree printed in preorder is
5 3 2 4 6 7 
************Main Menu***************
1.To insert element
2.To delete element
3.To print using inorder
4.To print using preorder
5.To print using postorder
6.To exit
***************************
5
Tree printed in postorder is
2 4 3 7 6 5 
************Main Menu***************
1.To insert element
2.To delete element
3.To print using inorder
4.To print using preorder
5.To print using postorder
6.To exit
***************************
2
Enter data to be deleted
5
************Main Menu***************
1.To insert element
2.To delete element
3.To print using inorder
4.To print using preorder
5.To print using postorder
6.To exit
***************************
2
Enter data to be deleted
3
************Main Menu***************
1.To insert element
2.To delete element
3.To print using inorder
4.To print using preorder
5.To print using postorder
6.To exit
***************************
3
Tree printed inorder is
2 4 6 7 
************Main Menu***************
1.To insert element
2.To delete element
3.To print using inorder
4.To print using preorder
5.To print using postorder
6.To exit
***************************
4
Tree printed in preorder is
6 4 2 7 
************Main Menu***************
1.To insert element
2.To delete element
3.To print using inorder
4.To print using preorder
5.To print using postorder
6.To exit
***************************
5
Tree printed in postorder is
2 4 7 6 
************Main Menu***************
1.To insert element
2.To delete element
3.To print using inorder
4.To print using preorder
5.To print using postorder
6.To exit
***************************
6
Program terminated, Thank You
*/
