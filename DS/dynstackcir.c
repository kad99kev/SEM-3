/*
 Title   : Implementation of stack using Circular Linked List (CLL)
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 */

#include <stdio.h>
#include<stdlib.h>

typedef struct node //Node Declaration
{
    int info;
    struct node *next;
}nd;

nd *TOP;

void createStack() //Stack creation
{
    TOP=NULL;
}

int isEmpty() //To check if stack is empty
{
    if(TOP==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int x) //To push element in stack
{
    nd *newnode=(nd *)malloc(sizeof(nd));
    newnode->info=x;
    if(isEmpty())
    {
        TOP=newnode;
        newnode->next=TOP;
    }
    else if(TOP->next==TOP)
    {
        TOP->next=newnode;
        newnode->next=TOP;
        TOP=newnode;
    }
    else
    {
        nd *ptr;
        ptr=TOP;
        while(ptr->next!=TOP)
        {
            ptr=ptr->next;
        }
        newnode->next=TOP;
        TOP=newnode;
        ptr->next=TOP;
    }
}

void pop()//To pop element out of stack
{
    nd *ptr, *temp;
    ptr=TOP;
    if(isEmpty())
    {
        printf("List Empty\n");
    }
    else if(TOP->next==TOP)
    {
        printf("Element popped is %d\n", ptr->info);
        free(ptr);
        TOP=NULL;
    }
    else
    {
        do
        {
            ptr=ptr->next;
        }while(ptr->next!=TOP);
        temp=TOP;
        ptr->next=temp->next;
        TOP=temp->next;
        printf("Element popped is %d\n", temp->info);
        free(temp);
    }
}

void peek() //To check element at the top
{
    nd *ptr, *preptr;
    ptr=TOP;
    if(isEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Element at the top is %d\n", TOP->info);
    }
}

void count() //To count number of elements
{
    int count=0;
    nd *ptr;
    ptr=TOP;
    if(isEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        do
        {
            count++;
            ptr=ptr->next;
        }while(ptr!=TOP);
        printf("There are %d elements in the stack\n", count);
    }
}

void display() //To display stack
{
    nd *ptr, *preptr;
    ptr=TOP;
    if(TOP==NULL)
        printf("List is empty\n");
    else
    {
        do
        {
            printf("%d\n",ptr->info);
            ptr=ptr->next;
        }while(ptr!=TOP);
    }
}

void main()
{
    int x, ch=0;
    createStack();
    do
    {
        printf("************Main Menu***************\n 1.To push\n 2.To pop\n 3.To peek\n 4.To count number of elements\n 5.To display list\n 6.To quit\n***************************\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            {
                printf("Enter data to be stored\n");
                scanf("%d", &x);
                push(x);
                break;
            }
                
            case 2:
            {
                pop();
                break;
            }
                
            case 3:
            {
                peek();
                break;
            }
                
            case 4:
            {
                count();
                break;
            }
                
            case 5:
            {
                printf("Elements in the stack\n");
                display();
                break;
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
    if(isEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Elements in the stack are\n");
        display();
    }
}

/*
 ************Main Menu***************
 1.To push
 2.To pop
 3.To peek
 4.To count number of elements
 5.To display list
 6.To quit
 ***************************
 1
 Enter data to be stored
 5
 ************Main Menu***************
 1.To push
 2.To pop
 3.To peek
 4.To count number of elements
 5.To display list
 6.To quit
 ***************************
 1
 Enter data to be stored
 4
 ************Main Menu***************
 1.To push
 2.To pop
 3.To peek
 4.To count number of elements
 5.To display list
 6.To quit
 ***************************
 1
 Enter data to be stored
 3
 ************Main Menu***************
 1.To push
 2.To pop
 3.To peek
 4.To count number of elements
 5.To display list
 6.To quit
 ***************************
 1
 Enter data to be stored
 6
 ************Main Menu***************
 1.To push
 2.To pop
 3.To peek
 4.To count number of elements
 5.To display list
 6.To quit
 ***************************
 1
 Enter data to be stored
 7
 ************Main Menu***************
 1.To push
 2.To pop
 3.To peek
 4.To count number of elements
 5.To display list
 6.To quit
 ***************************
 2
 Element popped is 7
 ************Main Menu***************
 1.To push
 2.To pop
 3.To peek
 4.To count number of elements
 5.To display list
 6.To quit
 ***************************
 2
 Element popped is 6
 ************Main Menu***************
 1.To push
 2.To pop
 3.To peek
 4.To count number of elements
 5.To display list
 6.To quit
 ***************************
 1
 Enter data to be stored
 2
 ************Main Menu***************
 1.To push
 2.To pop
 3.To peek
 4.To count number of elements
 5.To display list
 6.To quit
 ***************************
 1
 Enter data to be stored
 1
 ************Main Menu***************
 1.To push
 2.To pop
 3.To peek
 4.To count number of elements
 5.To display list
 6.To quit
 ***************************
 3
 Element at the top is 1
 ************Main Menu***************
 1.To push
 2.To pop
 3.To peek
 4.To count number of elements
 5.To display list
 6.To quit
 ***************************
 4
 There are 5 elements in the stack
 ************Main Menu***************
 1.To push
 2.To pop
 3.To peek
 4.To count number of elements
 5.To display list
 6.To quit
 ***************************
 6
 Program terminated, Thank You
 Elements in the stack are
 1
 2
 3
 4
 5
 */
