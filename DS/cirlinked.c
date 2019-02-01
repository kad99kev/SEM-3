/*
 Title   : Implementation of Circular Linked List (CLL)
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 */

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
        p->next=START;
    }
    else if(START->next==START)
    {
        START->next=p;
        p->next=START;
        START=p;
    }
    else
    {
        nd *ptr;
        ptr=START;
        while(ptr->next!=START)
        {
            ptr=ptr->next;
        }
        p->next=START;
        START=p;
        ptr->next=START;
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
        p->next=START;
    }
    else
    {
        ptr=START;
        while(ptr->next!=START)
            ptr=ptr->next;
        ptr->next=p;
        p->next=START;
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
        p->next=START;
    }
    else if(START->info==nodeinfo)
    {
        ptr=START;
        while(ptr->next!=START)
            ptr=ptr->next;
        p->next=START;
        START=p;
        ptr->next=START;
    }
    else
    {
        ptr=START;
        while(ptr->info!=nodeinfo && ptr->next!=START)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        if(ptr->info!=nodeinfo && ptr->next==START)
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
    p=(nd *)malloc(sizeof(nd)); //newinfo=new node info, nodeinfo=desired node info
    nd *ptr;
    ptr=START;
    if(START==NULL)
    {
        START=p;
        p->info=newinfo;
        p->next=START;
    }
    else
    {
        while(ptr->info!=nodeinfo && ptr->next!=START)
        {
            ptr=ptr->next;
            
        }
        if(ptr->info==nodeinfo && ptr->next==START)
        {
            p->next=START;
            ptr->next=p;
            p->info=newinfo;
        }
        else if(ptr->info!=nodeinfo && ptr->next==START)
        {
            printf("Node not found\n");
            return 0;
        }
        else
        {
            p->next=ptr->next;
            ptr->next=p;
            p->info=newinfo;
        }
    }
    return 1;
}


void Display() //To display list
{
    nd *ptr, *preptr;
    ptr=START;
    if(START==NULL)
        printf("List is empty\n");
    else
    {
        do
        {
            printf("%d ",ptr->info);
            ptr=ptr->next;
        }while(ptr!=START);
        printf("\n");
    }
}

int Delete_Node(int x) //To delete particular node
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
        printf("Deleted info=%d\n", ptr->info);
        while(ptr->next!=START)
        {
            ptr=ptr->next;
        }
        ptr->next=START->next;
        START=START->next;
        free(ptr);
    }
    else if(START->info == x && START->next==START)
    {
    	printf("Deleted info=%d\n", ptr->info);
    	free(ptr);
    	START=NULL;
    }
    else
    {
        while(ptr->info!=x && ptr->next!=START)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        if(ptr->info!=x && ptr->next==START)
        {
            printf("Node not found\n");
            return 0;
        }
        else
        {
            preptr->next=ptr->next;
            printf("Deleted info=%d\n", ptr->info);
            free(ptr);
        }
    }
    return 1;
}

int Delete_Before(int x) //To delete before particular node
{
    nd *ptr, *preptr, *temp;
    ptr=START;
    preptr=START;
    temp=START;
    if(START==NULL)
    {
        printf("List Empty\n");
        return 0;
    }
    else if(START->info==x)
    {
    	while(ptr->next!=START)
    	{
    		preptr=ptr;
    		ptr=ptr->next;
    	}
    	preptr->next=START;
    	printf("Deleted info=%d\n", ptr->info);
    	free(ptr);
    }
    else if(START->next==START)
    {
    	printf("Deleted info=%d\n", ptr->info);
    	free(ptr);
    	START=NULL;
    }
    else
    {
        while(ptr->info!=x && ptr->next!=START)
        {
            temp=preptr;
            preptr=ptr;
            ptr=ptr->next;
        }
        if(ptr->info!=x && ptr->next==START)
        {
            printf("Node not found\n");
            return 0;
        }
        else
        {
            if(preptr==START)
            {
            	while(ptr->next!=START)
            	{
            		ptr=ptr->next;
            	}
            	ptr->next=preptr->next;
            	START=ptr->next;
            	free(preptr);
            }
            else
            {
            	temp->next=ptr;
           	printf("Deleted info=%d\n", preptr->info);
           	free(preptr);
            }
        
        }
        
    }
    
        
    return 1;
    
}
int Delete_After(int x) //To delete after particular node
{
    nd *ptr, *preptr;
    ptr=START;
    preptr=START;
    if(START==NULL)
    {
        printf("List Empty\n");
        return 0;
    }
    else if(START->next==START)
    {
    	printf("TEST\n");
    	printf("Deleted info=%d\n", ptr->info);
    	free(ptr);
    	START=NULL;
    }
    else
    {
    	
        do
        {
            preptr=ptr;
            ptr=ptr->next;
        }while(preptr->info!=x && preptr->next!=START);
        if(preptr->info!=x && preptr->next==START)
        {
            printf("Node not found\n");
            return 0;
        }
        else
        {
            preptr->next=ptr->next;
            if(ptr==START)
            {
                START=START->next;
            }
            printf("Deleted info=%d\n", ptr->info);
            free(ptr);
        }
    }
    return 1;
    
}

int Delete_Begin()//To delete first node
{
    nd *ptr, *temp;
    ptr=START;
    if(START==NULL)
    {
        printf("List Empty\n");
        return 0;
    }
    else if(START->next==START)
    {
    	printf("Deleted info=%d\n", ptr->info);
    	free(ptr);
    	START=NULL;
    }
    else
    {
        do
        {
            ptr=ptr->next;
        }while(ptr->next!=START);
        temp=START;
        ptr->next=temp->next;
        START=temp->next;
        printf("Deleted info=%d\n", temp->info);
        free(temp);
    }
    return 1;
}

int Delete_End() //To delete last node
{
    nd *ptr, *temp;
    ptr=START;
    if(START==NULL)
    {
        printf("List Empty\n");
        return 0;
    }
    else if(START->next==START)
    {
    	printf("Deleted info=%d\n", ptr->info);
    	free(ptr);
    	START=NULL;
    }
    else
    {
        do
        {
            temp=ptr;
            ptr=ptr->next;
        }while(ptr->next!=START);
        temp->next=START;
        printf("Deleted info=%d\n", ptr->info);
        free(ptr);
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
        do
        {
            ptr=ptr->next;
            count++;
        }while(ptr!=START);
    }
    printf("Total number of nodes are %d\n", count);
}

void Reverse() //To reverse list
{
    nd *curr, *pre=NULL, *next=NULL;
    curr=START;
    do
    {
        next=curr->next;
        curr->next=pre;
        pre=curr;
        curr=next;
        
    }while(curr!=START);
    START->next=pre;
    START=pre;
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
        printf("************Main Menu***************\n 1.To insert at beginning\n 2.To insert at end\n 3.To add before a particular node\n 4.To insert after a particular node\n 5.To delete a particular node\n 6.To delete before a particular node\n 7.To delete after a particular node\n 8.To delete first node\n 9.To delete last node\n 10.To Reverse\n 11.To display list\n 12.To count number of nodes\n 13.To quit\n***************************\n");
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
                check=Delete_Node(y);
                if(check==1)
                    i--;
                break;
            }
            
            case 6:
            {
            	printf("Enter data of node to which the node before would be deleted\n");
                int y;
                scanf("%d", &y);
                check=Delete_Before(y);
                if(check==1)
                    i--;
                break;
            }
            
            case 7:
            {
            	printf("Enter data of node to which the node after would be deleted\n");
                int y;
                scanf("%d", &y);
                check=Delete_After(y);
                if(check==1)
                    i--;
                break;
            }
            
            case 8:
            {
                check=Delete_Begin();
                if(check==1)
                    i--;
                break;
            }
               
            case 9:
            {
                check=Delete_End();
                if(check==1)
                    i--;
                break;
            }
             
            case 10:
            {
                 printf("List before reversing\n");
                 Display();
                 Reverse();
                 printf("List after reversing\n");
                 Display();
                 break;
             }
                
            case 11:
            {
                printf("Elements in list\n");
                Display();
                break;
            }
            case 12:
            {
                Count();
                break;
            }
                
            case 13:
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
    }while(ch!=13 && i<a);
    printf("Final list is\n");
    Display();
    
}
/*
 Enter number of nodes to be created
 3
 ************Main Menu***************
 1.To insert at beginning
 2.To insert at end
 3.To add before a particular node
 4.To insert after a particular node
 5.To delete a particular node
 6.To delete before a particular node
 7.To delete after a particular node
 8.To delete first node
 9.To delete last node
 10.To Reverse
 11.To display list
 12.To count number of nodes
 13.To quit
 ***************************
 More than 3 nodes cannot be created, this is node 1
 1
 Enter data to be stored
 10
 ************Main Menu***************
 1.To insert at beginning
 2.To insert at end
 3.To add before a particular node
 4.To insert after a particular node
 5.To delete a particular node
 6.To delete before a particular node
 7.To delete after a particular node
 8.To delete first node
 9.To delete last node
 10.To Reverse
 11.To display list
 12.To count number of nodes
 13.To quit
 ***************************
 More than 3 nodes cannot be created, this is node 2
 2
 Enter data to be stored
 20
 ************Main Menu***************
 1.To insert at beginning
 2.To insert at end
 3.To add before a particular node
 4.To insert after a particular node
 5.To delete a particular node
 6.To delete before a particular node
 7.To delete after a particular node
 8.To delete first node
 9.To delete last node
 10.To Reverse
 11.To display list
 12.To count number of nodes
 13.To quit
 ***************************
 More than 3 nodes cannot be created, this is node 3
 8
 Deleted info=10
 ************Main Menu***************
 1.To insert at beginning
 2.To insert at end
 3.To add before a particular node
 4.To insert after a particular node
 5.To delete a particular node
 6.To delete before a particular node
 7.To delete after a particular node
 8.To delete first node
 9.To delete last node
 10.To Reverse
 11.To display list
 12.To count number of nodes
 13.To quit
 ***************************
 More than 3 nodes cannot be created, this is node 2
 3
 Enter data of node to which new node will be added before
 20
 Enter data for newnode
 30
 ************Main Menu***************
 1.To insert at beginning
 2.To insert at end
 3.To add before a particular node
 4.To insert after a particular node
 5.To delete a particular node
 6.To delete before a particular node
 7.To delete after a particular node
 8.To delete first node
 9.To delete last node
 10.To Reverse
 11.To display list
 12.To count number of nodes
 13.To quit
 ***************************
 More than 3 nodes cannot be created, this is node 3
 9
 Deleted info=20
 ************Main Menu***************
 1.To insert at beginning
 2.To insert at end
 3.To add before a particular node
 4.To insert after a particular node
 5.To delete a particular node
 6.To delete before a particular node
 7.To delete after a particular node
 8.To delete first node
 9.To delete last node
 10.To Reverse
 11.To display list
 12.To count number of nodes
 13.To quit
 ***************************
 More than 3 nodes cannot be created, this is node 2
 4
 Enter data of node to which new node will be added after
 30
 Enter data for newnode
 40
 ************Main Menu***************
 1.To insert at beginning
 2.To insert at end
 3.To add before a particular node
 4.To insert after a particular node
 5.To delete a particular node
 6.To delete before a particular node
 7.To delete after a particular node
 8.To delete first node
 9.To delete last node
 10.To Reverse
 11.To display list
 12.To count number of nodes
 13.To quit
 ***************************
 More than 3 nodes cannot be created, this is node 3
 6
 Enter data of node to which the node before would be deleted
 40
 ************Main Menu***************
 1.To insert at beginning
 2.To insert at end
 3.To add before a particular node
 4.To insert after a particular node
 5.To delete a particular node
 6.To delete before a particular node
 7.To delete after a particular node
 8.To delete first node
 9.To delete last node
 10.To Reverse
 11.To display list
 12.To count number of nodes
 13.To quit
 ***************************
 More than 3 nodes cannot be created, this is node 2
 1
 Enter data to be stored
 50
 ************Main Menu***************
 1.To insert at beginning
 2.To insert at end
 3.To add before a particular node
 4.To insert after a particular node
 5.To delete a particular node
 6.To delete before a particular node
 7.To delete after a particular node
 8.To delete first node
 9.To delete last node
 10.To Reverse
 11.To display list
 12.To count number of nodes
 13.To quit
 ***************************
 More than 3 nodes cannot be created, this is node 3
 7
 Enter data of node to which the node after would be deleted
 50
 Deleted info=40
 ************Main Menu***************
 1.To insert at beginning
 2.To insert at end
 3.To add before a particular node
 4.To insert after a particular node
 5.To delete a particular node
 6.To delete before a particular node
 7.To delete after a particular node
 8.To delete first node
 9.To delete last node
 10.To Reverse
 11.To display list
 12.To count number of nodes
 13.To quit
 ***************************
 More than 3 nodes cannot be created, this is node 2
 4
 Enter data of node to which new node will be added after
 50
 Enter data for newnode
 60
 ************Main Menu***************
 1.To insert at beginning
 2.To insert at end
 3.To add before a particular node
 4.To insert after a particular node
 5.To delete a particular node
 6.To delete before a particular node
 7.To delete after a particular node
 8.To delete first node
 9.To delete last node
 10.To Reverse
 11.To display list
 12.To count number of nodes
 13.To quit
 ***************************
 More than 3 nodes cannot be created, this is node 3
 10
 List before reversing
 50 60
 List after reversing
 60 50
 ************Main Menu***************
 1.To insert at beginning
 2.To insert at end
 3.To add before a particular node
 4.To insert after a particular node
 5.To delete a particular node
 6.To delete before a particular node
 7.To delete after a particular node
 8.To delete first node
 9.To delete last node
 10.To Reverse
 11.To display list
 12.To count number of nodes
 13.To quit
 ***************************
 More than 3 nodes cannot be created, this is node 3
 1
 Enter data to be stored
 70
 Final list is
 70 60 50
 */
