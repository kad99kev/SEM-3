/*
 Title   : Static Implementation of Linear queue
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 */

#include <stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct node //Node Declaration
{
    int row, col, info;
    struct node *next;
}nd;

nd*START=NULL;

void End(int r,int c, int d) //To insert node at the end
{
    nd *p;
    p=(nd *)malloc(sizeof(nd));
    nd *ptr;
    p->row=r;
    p->col=c;
    p->info=d;
    if(START==NULL)
    {
        START=p;
        p->next=NULL;
    }
    else
    {
        ptr=START;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=p;
        p->next=NULL;
    }
}

int Display(int r, int c) //To only display elements that contain information
{
    nd *ptr;
    int x;
    ptr=START;
    while(ptr!=NULL)
    {
        if(ptr->row==r && ptr->col==c)
        {
            return ptr->info;
        }
        else
            ptr=ptr->next;
    }
    return 0;
}

void main()
{
    int rows, cols, data;
    printf("Enter number of rows and columns for matrix\n");
    scanf("%d%d", &rows, &cols);
    printf("Enter values for matrix\n");
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            scanf("%d", &data);
            if(data!=0)
            {
                End(i,j,data);
            }
        }
        
    }
    printf("Values entered in matrix are\n");
    
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("%d ", Display(i,j));
        }
        printf("\n");
        
    }
}

/*
 Enter number of rows and columns for matrix
 2
 2
 Enter values for matrix
 0
 0
 3
 0
 Values entered in matrix are
 0 0
 3 0
 Enter number of rows and columns for matrix
 4
 5
 Enter values for matrix
 0
 0
 3
 0
 4
 0
 0
 5
 7
 0
 0
 0
 0
 0
 0
 0
 2
 6
 0
 0
 Values entered in matrix are
 0 0 3 0 4
 0 0 5 7 0
 0 0 0 0 0
 0 2 6 0 0
 */
