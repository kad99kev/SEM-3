/*
 Title   : Implementation of doubly linked list
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 */

#include <stdio.h>
#include<stdlib.h>

typedef struct node //Node Declaration
{
    int info;
    struct node *next, *prev;
}nd;

nd *START=NULL;

void begin(nd *p, int x) //To insert node at the beginning
{
    p=(nd *)malloc(sizeof(nd));
    p->info=x;
    if(START==NULL)
    {
        START=p;
        p->next=NULL;
        p->prev=NULL;
    }
   
    else
    {
        
        p->next=START;
        p->prev=NULL;
        START->prev=p;
        START=p;
    }
}

void end(nd *p, int x) //To insert node at the end
{
    p=(nd *)malloc(sizeof(nd));
    nd *ptr;
    p->info=x;
    if(START==NULL)
    {
        START=p;
        p->next=NULL;
        p->prev=NULL;
    }
    else
    {
        ptr=START;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=p;
        p->prev=ptr;
        p->next=NULL;
    }
}

int before(nd *p, int newinfo, int nodeinfo) //To insert node before particular node
{
    p=(nd *)malloc(sizeof(nd)); //newinfo=new node info, nodeinfo=desired node info
    nd *ptr;
    p->info=newinfo;
    if(START==NULL)
    {
        START=p;
        p->next=NULL;
        p->prev=NULL;
    }
    else if(START->info==nodeinfo)
    {
        START->prev=p;
        p->next=START;
        p->prev=NULL;
        START=p;
    }
    else
    {
       
        ptr=START;
        while(ptr->info!=nodeinfo && ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        if(ptr->info!=nodeinfo && ptr->next==NULL)
        {
            printf("Node not found\n");
            return 0;
        }
        else
        {
            p->next=ptr;
            ptr->prev->next=p;
            p->prev=ptr->prev;
            ptr->prev=p;
        }
    }
    return 1;
    
}

int after(nd *p, int newinfo, int nodeinfo) //To insert node before particular node
{
    p=(nd *)malloc(sizeof(nd)); //newinfo=new node info, nodeinfo=desired node info
    nd *ptr;
    ptr=START;
    if(START==NULL)
    {
        START=p;
        p->info=newinfo;
        p->prev=NULL;
        p->next=NULL;
    }
    else
    {
        while(ptr->info!=nodeinfo && ptr->next!=START)
        {
            ptr=ptr->next;
            
        }
        if(ptr->info==nodeinfo && ptr->next==NULL)
        {
            p->prev=ptr;
            p->next=NULL;
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
            p->prev=ptr;
            p->next=ptr->next;
            ptr->next->prev=p;
            ptr->next=p;
            p->info=newinfo;
        }
    }
    return 1;
}

void display() //To display list
{
    nd *ptr, *preptr;
    ptr=START;
    if(START==NULL)
    {
        printf("List is empty\n");
    }
    
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

int delete_node(int x) //To delete particular node
{
    nd *ptr;
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
        ptr->prev=NULL;
        free(ptr);
    }
    else
    {
        while(ptr->info!=x && ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        if(ptr->info!=x && ptr->next==NULL)
        {
            printf("Node not found\n");
            return 0;
        }
        else
        {
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            printf("Deleted info=%d\n", ptr->info);
            free(ptr);
        }
    }
    return 1;
}

int delete_before(int x) //Deletes before particular node
{
    nd *ptr;
    ptr=START;
    if(START==NULL)
    {
        printf("List Empty\n");
        return 0;
    }
    else if(START->info==x)
    {
        printf("Cannot delete before first node\n");
        return 0;
    }
    else
    {
        while(ptr->info!=x && ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        if(ptr->info!=x && ptr->next==NULL)
        {
            printf("Node not found\n");
            return 0;
        }
        else
        {
            ptr=ptr->prev;
            if(START==ptr)
            {
                START=ptr->next;
                ptr->next->prev=NULL;
                printf("Deleted info=%d\n", ptr->info);
                free(ptr);
            }
            else
            {
                ptr->prev->next=ptr->next;
                ptr->next->prev=ptr->prev;
                printf("Deleted info=%d\n", ptr->info);
                free(ptr);
            }
        }
    }
    return 1;
    
}
int delete_after(int x) //Deletes after particular node
{
    nd *ptr;
    ptr=START;
    if(START==NULL)
    {
        printf("List Empty\n");
        return 0;
    }
    else
    {
        while(ptr->info!=x && ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        if(ptr->info!=x && ptr->next==NULL)
        {
            
            printf("Node not found\n");
            return 0;
        }
        else if(ptr->info==x && ptr->next==NULL)
        {
            printf("Cannot delete after last node\n");
            return 0;
        }
        else
        {
            ptr=ptr->next;
            ptr->prev->next=ptr->next;
            if(ptr->next!=NULL)
            {
                ptr->next->prev=ptr->prev;
            }
            printf("Deleted info=%d\n", ptr->info);
            free(ptr);
        }
    }
    return 1;
    
}

int delete_begin() //Deletes first node
{
    nd *ptr, *temp;
    ptr=START;
    if(START==NULL)
    {
        printf("List Empty\n");
        return 0;
    }
    else if(ptr->next==NULL)
    {
        printf("Deleted info=%d\n", ptr->info);
        free(ptr);
        START=NULL;
    }
    else
    {
        temp=ptr;
        START=ptr->next;
        ptr=START;
        ptr->prev=NULL;
        printf("Deleted info=%d\n", temp->info);
        free(temp);
    }
    return 1;
}

int delete_end() //Deletes last node
{
    nd *ptr, *temp;
    ptr=START;
    if(START==NULL)
    {
        printf("List Empty\n");
        return 0;
    }
    else if(ptr->next==NULL)
    {
        printf("Deleted info=%d\n", ptr->info);
        free(ptr);
        START=NULL;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
            temp=ptr;
            ptr=ptr->prev;
            ptr->next=NULL;
            printf("Deleted info=%d\n", temp->info);
            free(temp);
    }
    return 1;
    
}

void count() //To count number of nodes
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

void reverse() //To reverse list
{
    nd *curr, *ptr;
    curr=START;
    while(curr!=NULL)
    {
        ptr=curr->prev;
        curr->prev=curr->next;
        curr->next=ptr;
        curr=curr->prev;
        
    }
    START=ptr->prev;
}


void main()
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
                begin(&node[i],x);
                i++;
                break;
            }
            case 2:
            {
                printf("Enter data to be stored\n");
                scanf("%d", &x);
                end(&node[i],x);
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
                check=before(&node[i],x,y);
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
                check=after(&node[i],x,y);
                if(check==1)
                    i++;
                break;
            }
                
            case 5:
            {
                printf("Enter data of node to which node would be deleted\n");
                int y;
                scanf("%d", &y);
                check=delete_node(y);
                if(check==1)
                    i--;
                break;
            }
                
            case 6:
            {
                printf("Enter data of node to which the node before would be deleted\n");
                int y;
                scanf("%d", &y);
                check=delete_before(y);
                if(check==1)
                    i--;
                break;
            }
                
            case 7:
            {
                printf("Enter data of node to which the node after would be deleted\n");
                int y;
                scanf("%d", &y);
                check=delete_after(y);
                if(check==1)
                    i--;
                break;
            }
                
            case 8:
            {
                check=delete_begin();
                if(check==1)
                    i--;
                break;
            }
                
            case 9:
            {
                check=delete_end();
                if(check==1)
                    i--;
                break;
            }
                
            case 10:
            {
                printf("List before reversing\n");
                display();
                reverse();
                printf("List after reversing\n");
                display();
                break;
            }
                
            case 11:
            {
                printf("Elements in list\n");
                display();
                break;
            }
            case 12:
            {
                count();
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
    display();
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
 1
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
 2
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
 Deleted info=1
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
 2
 Enter data for newnode
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
 More than 3 nodes cannot be created, this is node 3
 9
 Deleted info=2
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
 3
 Enter data for newnode
 4
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
 4
 Deleted info=3
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
 5
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
 5
 Deleted info=4
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
 5
 Enter data for newnode
 6
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
 5 6
 List after reversing
 6 5
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
 7
 Final list is
 7 6 5
*/
 
