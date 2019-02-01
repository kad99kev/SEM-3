//
//  teststack.c
//  
//
//  Created by Kevlyn Kadamala on 31/10/18.
//

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
        while(ptr->next != TOP)
        {
            ptr = ptr->next;
        }
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
    createStack();
    push(10);
    pop();
    push(20);
    push(30);
    push(50);
    pop();
    push(40);
    push(70);
    push(80);
    pop();
    peek();
    count();
    display();
}



