/*
 Title   : Dynamic implementation of Deque
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 */

#include <stdio.h>
#include <stdio.h>
#include<stdlib.h>

/*-----Linked List------*/
typedef struct node //Node Declaration
{
    int info;
    struct node *next;
}nd;

nd *begin(nd *p, int x) //To insert node at the beginning
{
    nd *START;
    START=p;
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
    return START;
}

nd *end(nd *p, int x) //To insert node at the end
{
    nd *START;
    START=p;
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
    return START;
}

nd *delete_front(nd *START)//To delete first node
{
    nd *ptr;
    ptr=START;
    if(START==NULL)
    {
        printf("List Empty\n");
        return 0;
    }
    else if(START->next==NULL)
    {
        printf("Element deleted is %d\n", ptr->info);
        free(ptr);
        START=NULL;
    }
    else
    {
        ptr=START;
        START=START->next;
        printf("Element deleted is %d\n", ptr->info);
        free(ptr);
    }
    return START;
}

nd *delete_rear(nd *START) //To delete last node
{
    nd *ptr, *temp;
    ptr=START;
    if(START==NULL)
    {
        printf("List Empty\n");
        return 0;
    }
    else if(START->next==NULL)
    {
        printf("Element deleted is %d\n", ptr->info);
        free(ptr);
        START=NULL;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next=NULL;
        printf("Element deleted is %d\n", ptr->info);
        free(ptr);
    }
    return START;
    
}

void display_list(nd *START) //To display list
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

void main()
{
    int ch=0, check=0, x;
    nd *irlist, *orlist;
    irlist=NULL;
    orlist=NULL;
    printf("Enter\n1. For input restricted queue OR 2. For output restricted queue\n");
    scanf("%d", &ch);
    switch (ch)
    {
        case 1:
            {
                do
                {
                    printf("Enter\n1. To enqueue\n2. To dequeue from front\n3. To dequeue from rear\n4. To exit\n");
                    scanf("%d", &check);
                    switch (check)
                    {
                        case 1:
                            {
                                printf("Enter element to be enqueued\n");
                                scanf("%d", &x);
                                irlist=end(irlist, x);
                                break;
                            }
                        case 2:
                        {
                            irlist=delete_front(irlist);
                            break;
                        }
                        case 3:
                        {
                            irlist=delete_rear(irlist);
                            break;
                        }
                        case 4:
                        {
                            check=0;
                            break;
                        }
                            
                        default: printf("Invalid entry\n");
                            break;
                    }
                }while(check!=0);
                    printf("Elements in the queue are\n");
                display_list(irlist);
            }
            break;
            
        case 2:
        {
            do
            {
                printf("Enter\n1. To enqueue from front\n2 To enqueue from rear\n3. To dequeue\n4. To exit\n");
                scanf("%d", &check);
                switch (check)
                {
                    case 1:
                    {
                        printf("Enter element to be enqueued\n");
                        scanf("%d", &x);
                        orlist=begin(orlist, x);
                        break;
                    }
                    case 2:
                    {
                        printf("Enter element to be enqueued\n");
                        scanf("%d", &x);
                        orlist=end(orlist, x);
                        break;
                    }
                    case 3:
                    {
                        orlist=delete_front(orlist);
                        break;
                    }
                    case 4:
                    {
                        check=0;
                        break;
                    }
                        
                    default: printf("Invalid entry\n");
                        break;
                }
            }while(check!=0);
                printf("Elements in the queue are\n");
            display_list(orlist);
        }
            break;
            
        default: printf("Invalid entry\n");
            break;
    }
}

/*
 //Input restricted dynamic queue\\
 Enter
 1. For input restricted queue OR 2. For output restricted queue
 1
 Enter
 1. To enqueue
 2. To dequeue from front
 3. To dequeue from rear
 4. To exit
 1
 Enter element to be enqueued
 1
 Enter
 1. To enqueue
 2. To dequeue from front
 3. To dequeue from rear
 4. To exit
 1
 Enter element to be enqueued
 2
 Enter
 1. To enqueue
 2. To dequeue from front
 3. To dequeue from rear
 4. To exit
 1
 Enter element to be enqueued
 3
 Enter
 1. To enqueue
 2. To dequeue from front
 3. To dequeue from rear
 4. To exit
 1
 Enter element to be enqueued
 4
 Enter
 1. To enqueue
 2. To dequeue from front
 3. To dequeue from rear
 4. To exit
 1
 Enter element to be enqueued
 5
 Enter
 1. To enqueue
 2. To dequeue from front
 3. To dequeue from rear
 4. To exit
 2
 Element deleted is 1
 Enter
 1. To enqueue
 2. To dequeue from front
 3. To dequeue from rear
 4. To exit
 3
 Element deleted is 5
 Enter
 1. To enqueue
 2. To dequeue from front
 3. To dequeue from rear
 4. To exit
 4
 Elements in the queue are
 2 3 4
 
 //Output restricted dynamic queue\\
 Enter
 1. For input restricted queue OR 2. For output restricted queue
 2
 Enter
 1. To enqueue from front
 2 To enqueue from rear
 3. To dequeue
 4. To exit
 1
 Enter element to be enqueued
 1
 Enter
 1. To enqueue from front
 2 To enqueue from rear
 3. To dequeue
 4. To exit
 2
 Enter element to be enqueued
 2
 Enter
 1. To enqueue from front
 2 To enqueue from rear
 3. To dequeue
 4. To exit
 1
 Enter element to be enqueued
 3
 Enter
 1. To enqueue from front
 2 To enqueue from rear
 3. To dequeue
 4. To exit
 2
 Enter element to be enqueued
 4
 Enter
 1. To enqueue from front
 2 To enqueue from rear
 3. To dequeue
 4. To exit
 1
 Enter element to be enqueued
 5
 Enter
 1. To enqueue from front
 2 To enqueue from rear
 3. To dequeue
 4. To exit
 3
 Element deleted is 5
 Enter
 1. To enqueue from front
 2 To enqueue from rear
 3. To dequeue
 4. To exit
 3
 Element deleted is 3
 Enter
 1. To enqueue from front
 2 To enqueue from rear
 3. To dequeue
 4. To exit
 4
 Elements in the queue are
 1 2 4
*/
