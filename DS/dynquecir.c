/*
 Title   : Implementation of queue using Circular Linked List (CLL)
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


nd  *FRONT, *REAR;

void createQueue() //Queue creation
{
    FRONT=NULL;
    REAR=NULL;
}

void destroyQue() //Queue destruction
{
    FRONT=NULL;
    REAR=NULL;
}

int isEmpty() //To check if queue is empty
{
    if(REAR==NULL || FRONT==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enque(int x) //To enqueue elements
{
    nd *newnode=(nd *)malloc(sizeof(nd));
    nd *ptr;
    newnode->info=x;
    if(isEmpty())
    {
        FRONT=REAR=newnode;
        newnode->next=FRONT;
    }
    else
    {
        ptr=REAR;
        ptr->next=newnode;
        REAR=newnode;
        newnode->next=FRONT;
    }
}

void deque()//To dequeue element
{
    nd *ptr, *temp;
    ptr=FRONT;
    if(isEmpty())
    {
        printf("Queue Empty\n");
    }
    else if(FRONT->next==FRONT) //For last element
    {
        printf("Element dequeued is %d\n", ptr->info);
        free(ptr);
        destroyQue();
    }
    else
    {
        ptr=REAR;
        temp=FRONT;
        ptr->next=temp->next;
        FRONT=temp->next;
        printf("Element dequeued is %d\n", temp->info);
        free(temp);
    }
}

void count() //To count number of elements
{
    nd *ptr;
    int count=0;
    ptr=FRONT;
    if(isEmpty())
        printf("List is empty\n");
    else
    {
        do
        {
            ptr=ptr->next;
            count++;
        }while(ptr!=FRONT);
    }
    printf("Total number of nodes are %d\n", count);
}

void display() //To display queue
{
    nd *ptr, *preptr;
    ptr=FRONT;
    if(isEmpty())
        printf("List is empty\n");
    else
    {
        do
        {
            printf("%d ",ptr->info);
            ptr=ptr->next;
        }while(ptr!=FRONT);
        printf("\n");
    }
}

void main()
{
    int x, ch=0;
    createQueue();
    do
    {
        printf("************Main Menu***************\n 1.To enqueue\n 2.To dequeue\n 3.To count number of elements\n 4.To display list\n 5.To destroy queue\n 6.To quit\n***************************\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            {
                printf("Enter data to be stored\n");
                scanf("%d", &x);
                enque(x);
                break;
            }
                
            case 2:
            {
                deque();
                break;
            }
                
            case 3:
            {
                count();
                break;
            }
                
            case 4:
            {
                printf("Elements in queue\n");
                display();
                break;
            }
                
            case 5:
            {
                destroyQue();
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
        printf("Queue is empty\n");
    }
    else
    {
        printf("Elements in the queue are\n");
        display();
    }
}

/*
 ************Main Menu***************
 1.To enqueue
 2.To dequeue
 3.To count number of elements
 4.To display list
 5.To destroy queue
 6.To quit
 ***************************
 1
 Enter data to be stored
 6
 ************Main Menu***************
 1.To enqueue
 2.To dequeue
 3.To count number of elements
 4.To display list
 5.To destroy queue
 6.To quit
 ***************************
 1
 Enter data to be stored
 7
 ************Main Menu***************
 1.To enqueue
 2.To dequeue
 3.To count number of elements
 4.To display list
 5.To destroy queue
 6.To quit
 ***************************
 1
 Enter data to be stored
 1
 ************Main Menu***************
 1.To enqueue
 2.To dequeue
 3.To count number of elements
 4.To display list
 5.To destroy queue
 6.To quit
 ***************************
 1
 Enter data to be stored
 2
 ************Main Menu***************
 1.To enqueue
 2.To dequeue
 3.To count number of elements
 4.To display list
 5.To destroy queue
 6.To quit
 ***************************
 1
 Enter data to be stored
 3
 ************Main Menu***************
 1.To enqueue
 2.To dequeue
 3.To count number of elements
 4.To display list
 5.To destroy queue
 6.To quit
 ***************************
 1
 Enter data to be stored
 4
 ************Main Menu***************
 1.To enqueue
 2.To dequeue
 3.To count number of elements
 4.To display list
 5.To destroy queue
 6.To quit
 ***************************
 1
 Enter data to be stored
 5
 ************Main Menu***************
 1.To enqueue
 2.To dequeue
 3.To count number of elements
 4.To display list
 5.To destroy queue
 6.To quit
 ***************************
 2
 Element dequeued is 6
 ************Main Menu***************
 1.To enqueue
 2.To dequeue
 3.To count number of elements
 4.To display list
 5.To destroy queue
 6.To quit
 ***************************
 2
 Element dequeued is 7
 ************Main Menu***************
 1.To enqueue
 2.To dequeue
 3.To count number of elements
 4.To display list
 5.To destroy queue
 6.To quit
 ***************************
 3
 Total number of nodes are 5
 ************Main Menu***************
 1.To enqueue
 2.To dequeue
 3.To count number of elements
 4.To display list
 5.To destroy queue
 6.To quit
 ***************************
 6
 Program terminated, Thank You
 Elements in the queue are
 1 2 3 4 5
 */
