/*
 Title   : Implementation of Expression Tree
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 */

#include <stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct node
{
    char exp;
    struct node *left, *right;
}tr;

typedef struct stack
{
    int top;
    tr *arr[MAX];
}stk;

void initstk(stk *s)
{
    s->top=-1;
}

void push(tr *leaf, stk *s)
{
    s->arr[++s->top]=leaf;
}

tr *pop(stk *s)
{
    return s->arr[s->top--];
}

int isOperand(char c)
{
    if((c>='a' && c<='z') || (c>='A' && c<='Z'))
        return 1;
    else
        return 0;
}

void createTree(tr *leaf, stk *s, char c)
{
    leaf=(tr *)malloc(sizeof(tr));
    leaf->exp=c;
    leaf->left = NULL;
    leaf->right = NULL;
    if(!isOperand(c))
    {
        leaf->right=pop(s);
        leaf->left=pop(s);
        push(leaf, s);
    }
    else
    {
        push(leaf, s);
    }
}

tr *read(tr *leaf, char exp[])
{
    int i;
    stk s;
    initstk(&s);
    for(i=0; exp[i]!='\0'; i++)
    {
        createTree(leaf, &s, exp[i]);
    }
    leaf=pop(&s);
    return leaf;
}

int count_nodes(tr *leaf)
{
    int x;
    if(leaf!=NULL)
    {
        x=count_nodes(leaf->left)+count_nodes(leaf->right)+1;
        return x;
    }
    else
    {
        return 0;
    }
}

void display(tr *leaf)
{
    if(leaf!=NULL)
    {
        if(leaf->left!=NULL && leaf->right!=NULL)
            printf("(");
        display(leaf->left);
        printf("%c", leaf->exp);
        display(leaf->right);
        if(leaf->left!=NULL && leaf->right!=NULL)
            printf(")");
    }
}

void main()
{
    char exp[MAX];
    tr *root;
    root=NULL;
    printf("Enter postfix expression\n");
    gets(exp);
    root=read(root, exp);
    printf("Inorder expression is\n");
    display(root);
    printf("\n");
    printf("The number of nodes in the tree are %d\n", count_nodes(root));
}


/*
 Enter postfix expression
 ab+cde+**
 Inorder expression is
 ((a+b)*(c*(d+e)))
 The number of nodes in the tree are 9
 
 Enter postfix expression
 ab+cd+*
 Inorder expression is
 ((a+b)*(c+d))
 The number of nodes in the tree are 7
 
 Enter postfix expression
 ab+c*d-
 Inorder expression is
 (((a+b)*c)-d)
 The number of nodes in the tree are 7
 */
