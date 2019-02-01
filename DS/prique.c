/*
 Title   : Implementation of Priority Queue
 Name    : Kevlyn Kadamala
 Roll no.: 8340
*/

#include <stdio.h>
#include<stdlib.h>

typedef struct node //Node Declaration
{
    int data, pri;
    struct node *next;
}nd;

nd*START=NULL;

void insert() //To insert an element
{
    int pri, data;
    nd *newnode=(nd *)malloc(sizeof(nd));
    printf("Enter data\n");
    scanf("%d", &data);
    printf("Enter priority (0->Highest)\n");
    scanf("%d", &pri);

    newnode->data=data;
    newnode->pri=pri;
    if(START==NULL)
    {
        START=newnode;
        newnode->next=NULL;
    }
    else if(START->pri>pri) //Condition to check START priority
    {
        newnode->next=START;
        START=newnode;
    }
    else
    {
        nd *ptr=START;
        while(ptr->next!=NULL && pri>=ptr->next->pri) /*Condition to check priority and then add according to first come first serve*/
        {
            ptr=ptr->next;
        }
        newnode->next=ptr->next;
        ptr->next=newnode;
    }
}

void delete() //To dequeue element at the front end of the queue
{
    nd *temp;
    if(START==NULL)
    {
        printf("Queue empty\n");
    }
    else
    {
        temp=START;
        START=START->next;
        printf("Dequeued element is %d\n", temp->data);
        free(temp);
    }
}

void display() //To display elements in the queue
{
    nd *ptr;
    ptr=START;
    if(START==NULL)
    {
        printf("Queue empty\n");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d ", ptr->data);
            ptr=ptr->next;
        }
    }
    printf("\n");
}

void main()
{
    int check=1, ch;
    while(check)
    {
        printf("************Main Menu***************\n 1.To enqueue element\n 2.To dequeue element\n 3.To display queue\n 4.To exit\n***************************\n");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1:
            {
                insert();
                break;
            }
            case 2:
            {
                delete();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                check=0;
                break;
            }
            default:
            {
                printf("Invalid entry\n");
            }
        }
    }
    printf("Elements in the queue are\n");
    display();
}

/*
 Kevlyns-MacBook-Air:ds kad99kev$ ./a.out
 ************Main Menu***************
 1.To enqueue element
 2.To dequeue element
 3.To display queue
 4.To exit
 ***************************
 1
 Enter data
 10
 Enter priority (0->Highest)
 2
 ************Main Menu***************
 1.To enqueue element
 2.To dequeue element
 3.To display queue
 4.To exit
 ***************************
 1
 Enter data
 20
 Enter priority (0->Highest)
 0
 ************Main Menu***************
 1.To enqueue element
 2.To dequeue element
 3.To display queue
 4.To exit
 ***************************
 1
 Enter data
 30
 Enter priority (0->Highest)
 1
 ************Main Menu***************
 1.To enqueue element
 2.To dequeue element
 3.To display queue
 4.To exit
 ***************************
 1
 Enter data
 40
 Enter priority (0->Highest)
 3
 ************Main Menu***************
 1.To enqueue element
 2.To dequeue element
 3.To display queue
 4.To exit
 ***************************
 1
 Enter data
 50
 Enter priority (0->Highest)
 4
 ************Main Menu***************
 1.To enqueue element
 2.To dequeue element
 3.To display queue
 4.To exit
 ***************************
 1
 Enter data
 60
 Enter priority (0->Highest)
 0
 ************Main Menu***************
 1.To enqueue element
 2.To dequeue element
 3.To display queue
 4.To exit
 ***************************
 1
 Enter data
 70
 Enter priority (0->Highest)
 1
 ************Main Menu***************
 1.To enqueue element
 2.To dequeue element
 3.To display queue
 4.To exit
 ***************************
 2
 Dequeued element is 20
 ************Main Menu***************
 1.To enqueue element
 2.To dequeue element
 3.To display queue
 4.To exit
 ***************************
 1
 Enter data
 80
 Enter priority (0->Highest)
 0
 ************Main Menu***************
 1.To enqueue element
 2.To dequeue element
 3.To display queue
 4.To exit
 ***************************
 4
 Elements in the queue are
 60 80 30 70 10 40 50
 */
