//
//  prac1.c
//  
//
//  Created by Kevlyn Kadamala on 12/08/18.
//

#include <stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct node //Node Declaration
{
    int info;
    struct node *next;
}nd;

nd*START=NULL;

void Begin(nd *p, int x) //To insert node at the beginning
{
    p=(nd *)malloc(sizeof(nd));
    p->info=x;
  if(START==NULL)
  {
      START=p;
      p->next=NULL;
  }
    else
    {
        p->next=START;
        START=p;
    }
}

void End(nd *p, int x) //To insert node at the end
{
    p=(nd *)malloc(sizeof(nd));
    nd *ptr;
    p->info=x;
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

int Before(nd *p, int newinfo, int nodeinfo) //To insert node before particular node
{
    p=(nd *)malloc(sizeof(nd)); //newinfo=new node info, nodeinfo=desired node info
    nd *ptr, *preptr;
    p->info=newinfo;
    if(START==NULL)
    {
        START=p;
        p->next=NULL;
    }
    else if(START->info==nodeinfo)
    {
        p->next=START;
        START=p;
    }
    else
    {
        ptr=START;
        while(ptr->info!=nodeinfo && ptr->next!=NULL)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        if(ptr->info!=nodeinfo && ptr->next==NULL)
        {
            printf("Node not found\n");
            return 0;
        }
        else
        {
            preptr->next=p;
            p->next=ptr;
        }
    }
    return 1;
    
}

int After(nd *p, int newinfo, int nodeinfo) //To insert node before particular node
{
    nd *newnode=(nd *)malloc(sizeof(nd)); //newinfo=new node info, nodeinfo=desired node info
    nd *ptr;
    ptr=START;
    if(START==NULL)
    {
        START=newnode;
        newnode->info=newinfo;
        newnode->next=NULL;
    }
    else
    {
        while(ptr->info!=nodeinfo && ptr->next!=NULL)
        {
            ptr=ptr->next;
            
        }
        if(ptr->info==nodeinfo && ptr->next==NULL)
        {
            newnode->next=NULL;
            ptr->next=newnode;
            newnode->info=newinfo;
        }
        else if(ptr->info!=nodeinfo && ptr->next==NULL)
        {
            printf("Node not found\n");
            return 0;
        }
        else
        {
            newnode->next=ptr->next;
            ptr->next=newnode;
            newnode->info=newinfo;
        }
    }
    return 1;
}


void Display() //To display list
{
    nd *ptr;
    ptr=START;
    if(START==NULL)
        printf("List is empty\n");
    else
    {
        while(ptr!=NULL)
        {
            printf("%d ",ptr->info);
            ptr=ptr->next;
        }
        printf("\n");
    }
}

int Delete(int x) //To delete particular node
{
    nd *ptr, *preptr;
    ptr=START;
    if(START==NULL)
    {
        printf("List Empty\n");
        return 0;
    }
    else if(START->info==x)
    {
        START=ptr->next;
        printf("Deleted info=%d\n", ptr->info);
        free(ptr);
    }
    else
    {    while(ptr->info!=x && ptr->next != NULL)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        if(ptr->info!=x && ptr->next==NULL)
        {
            printf("Node not found\n");
            return 0;
        }
        else{
            preptr->next=ptr->next;
            printf("Deleted info= %d\n", ptr->info);
            free(ptr);
        }
    }
    return 1;
}

void Count() //To count number of nodes
{
    nd *ptr;
    int count=0;
    ptr=START;
    if(START==NULL)
        printf("List is empty\n");
    else
    {
        while(ptr!=NULL)
        {
            ptr=ptr->next;
            count++;
        }
    }
    printf("Total number of nodes are %d\n", count);
}

void Reverse() //To reverse list
{
    nd *curr, *pre=NULL, *next=NULL;
    curr=START;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=pre;
        pre=curr;
        curr=next;
        
    }
    START=pre;
}

void maxmin()
{
    nd *ptr;
    int max, min;
    ptr=START;
    max=min=ptr->info;
    while(ptr!=NULL)
    {
        if(ptr->info>max)
        {
            max=ptr->info;
        }
        if(ptr->info<min)
        {
            min=ptr->info;
        }
        
        ptr=ptr->next;
    }
    
    printf("Max=%d, Min=%d\n", max, min);
}


int main(void)
{
    int a;
    printf("Enter number of nodes to be created\n");
    scanf("%d", &a);
    nd node[a];
    int ch, n, x, check;
    int i=0;
    do
    {
        printf("************Main Menu***************\n 1.To insert at beginning\n 2.To insert at end\n 3.To add before a particular node\n 4.To insert after a particular node\n 5.To delete a particular node\n 6.To Reverse\n 7.To display list\n 8.To count number of nodes\n 9.To quit\n***************************\n");
        printf("More than %d nodes cannot be created, this is node %d\n", a, i+1);
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            {
                printf("Enter data to be stored\n");
                scanf("%d", &x);
                Begin(&node[i],x);
                i++;
                break;
            }
            case 2:
            {
                printf("Enter data to be stored\n");
                scanf("%d", &x);
                End(&node[i],x);
                i++;
                break;
            }
                
            case 3:
            {
                printf("Enter data of node to which new node will be added before\n");
                int y;
                scanf("%d", &y);
                printf("Enter data for newnode\n");
                scanf("%d", &x);
                check=Before(&node[i],x,y);
                if(check==1)
                    i++;
                break;
            }
            
            case 4:
            {
                printf("Enter data of node to which new node will be added after\n");
                int y;
                scanf("%d", &y);
                printf("Enter data for newnode\n");
                scanf("%d", &x);
                check=After(&node[i],x,y);
                if(check==1)
                    i++;
                break;
            }
                
            case 5:
            {
                printf("Enter data of node to which node would be deleted\n");
                int y;
                scanf("%d", &y);
                check=Delete(y);
                if(check==1)
                    i--;
                break;
            }
            
            case 6:
            {
                printf("List before reversing\n");
                Display();
                Reverse();
                printf("List after reversing\n");
                Display();
                break;
            }
                
            case 7:
            {
                printf("Elements in list\n");
                Display();
                break;
            }
                
            case 8:
            {
                Count();
                break;
            }
     
            case 9:
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
    }while(ch!=9 && i<a);
    printf("Final list is\n");
    Display();
    maxmin();
    
}
/*
 Enter number of nodes to be created
 5
 ************Main Menu***************
 1.To insert at beginning
 2.To insert at end
 3.To add before a particular node
 4.To insert after a particular node
 5.To delete a particular node
 6.To Reverse
 7.To display list
 8.To count number of nodes
 9.To quit
 ***************************
 More than 5 nodes cannot be created, this is node 1
 1
 Enter data to be stored
 10
 ************Main Menu***************
 1.To insert at beginning
 2.To insert at end
 3.To add before a particular node
 4.To insert after a particular node
 5.To delete a particular node
 6.To Reverse
 7.To display list
 8.To count number of nodes
 9.To quit
 ***************************
 More than 5 nodes cannot be created, this is node 2
 2
 Enter data to be stored
 60
 ************Main Menu***************
 1.To insert at beginning
 2.To insert at end
 3.To add before a particular node
 4.To insert after a particular node
 5.To delete a particular node
 6.To Reverse
 7.To display list
 8.To count number of nodes
 9.To quit
 ***************************
 More than 5 nodes cannot be created, this is node 3
 3
 Enter data of node to which new node will be added before
 60
 Enter data for newnode
 40
 ************Main Menu***************
 1.To insert at beginning
 2.To insert at end
 3.To add before a particular node
 4.To insert after a particular node
 5.To delete a particular node
 6.To Reverse
 7.To display list
 8.To count number of nodes
 9.To quit
 ***************************
 More than 5 nodes cannot be created, this is node 4
 4
 Enter data of node to which new node will be added after
 40
 Enter data for newnode
 50
 ************Main Menu***************
 1.To insert at beginning
 2.To insert at end
 3.To add before a particular node
 4.To insert after a particular node
 5.To delete a particular node
 6.To Reverse
 7.To display list
 8.To count number of nodes
 9.To quit
 ***************************
 More than 5 nodes cannot be created, this is node 5
 6
 List before reversing
 10 40 50 60
 List after reversing
 60 50 40 10
 ************Main Menu***************
 1.To insert at beginning
 2.To insert at end
 3.To add before a particular node
 4.To insert after a particular node
 5.To delete a particular node
 6.To Reverse
 7.To display list
 8.To count number of nodes
 9.To quit
 ***************************
 More than 5 nodes cannot be created, this is node 5
 5
 Enter data of node to which node would be deleted
 60
 Deleted info=60
 ************Main Menu***************
 1.To insert at beginning
 2.To insert at end
 3.To add before a particular node
 4.To insert after a particular node
 5.To delete a particular node
 6.To Reverse
 7.To display list
 8.To count number of nodes
 9.To quit
 ***************************
 More than 5 nodes cannot be created, this is node 4
 7
 Elements in list
 50 40 10
 ************Main Menu***************
 1.To insert at beginning
 2.To insert at end
 3.To add before a particular node
 4.To insert after a particular node
 5.To delete a particular node
 6.To Reverse
 7.To display list
 8.To count number of nodes
 9.To quit
 ***************************
 More than 5 nodes cannot be created, this is node 4
 8
 Total number of nodes are 3
 ************Main Menu***************
 1.To insert at beginning
 2.To insert at end
 3.To add before a particular node
 4.To insert after a particular node
 5.To delete a particular node
 6.To Reverse
 7.To display list
 8.To count number of nodes
 9.To quit
 ***************************
 More than 5 nodes cannot be created, this is node 4
 4
 Enter data of node to which new node will be added after
 30
 Enter data for newnode
 20
 Node not found
 ************Main Menu***************
 1.To insert at beginning
 2.To insert at end
 3.To add before a particular node
 4.To insert after a particular node
 5.To delete a particular node
 6.To Reverse
 7.To display list
 8.To count number of nodes
 9.To quit
 ***************************
 More than 5 nodes cannot be created, this is node 4
 4
 Enter data of node to which new node will be added after
 40
 Enter data for newnode
 30
 ************Main Menu***************
 1.To insert at beginning
 2.To insert at end
 3.To add before a particular node
 4.To insert after a particular node
 5.To delete a particular node
 6.To Reverse
 7.To display list
 8.To count number of nodes
 9.To quit
 ***************************
 More than 5 nodes cannot be created, this is node 5
 4
 Enter data of node to which new node will be added after
 30
 Enter data for newnode
 20
 Final list is
 50 40 30 20 10
 */
