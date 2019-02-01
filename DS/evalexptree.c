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
    if(c>='0' && c<='9')
        return 1;
    else
        return 0;
}

void createTree(tr *leaf, stk *s, char c)
{
    leaf=(tr *)malloc(sizeof(tr));
    leaf->exp=c;
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

int operate(tr *leaf)      //To perform desired operation
{
    int a, b, n=0;
    char o;
    
    if(leaf->left==NULL && leaf->right==NULL) //Terminating condition for operand node
        return leaf->exp-'0';
    
    a=operate(leaf->left); //Operates left subtree
    b=operate(leaf->right); //Operates right subtree
    
    o=leaf->exp; //Parent node consisting of operator
    switch(o)
    {
        case '+': n=a+b;
            break;
        case '-': n=a-b;
            break;
        case '*': n=a*b;
            break;
        case '/': n=a/b;
            break;
        case '%': n=a%b;
            break;
    }
    return n; //Returning result to parent operator
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

void main()
{
    char exp[MAX];
    tr *root;
    root=NULL;
    printf("Enter postfix expression\n");
    gets(exp);
    root=read(root, exp);
    printf("After evaluation\n");
    int res=operate(root);
    printf("%d\n", res);
}

/*
 Enter postfix expression
 12+345+**
 After evaluation
 81
 
 Enter postfix expression
 56+24+*
 After evaluation
 66
 
 Enter postfix expression
 34+7*9-
 After evaluation
 40
 */
