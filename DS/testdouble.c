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
        if(ptr->info!=nodeinfo && ptr->next==NULL)
        {
            printf("Node not found\n");
            return 0;
        }
        else
        {
            p->prev=ptr;
            p->next=ptr->next;
            if(ptr->next != NULL){
                ptr->next->prev=p;
            }
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

nd * insertionSort(nd *start, nd * ptr){
    nd *trav;
    if (start == NULL || start->info < ptr->info)
    {
        ptr->next = start;
        ptr->prev = NULL;
        if(start != NULL){
            start->prev = ptr;
        }
        start = ptr;
    }
    else{
        trav = start;
        while(trav->next != NULL && (ptr->info < trav->next->info)){
            trav = trav->next;
        }
        ptr->prev = trav;
        ptr->next = trav->next;
        if(trav->next != NULL){
            trav->next->prev = ptr;
        }
        trav->next = ptr;
    }
    return start;
}

void sort(){
    nd *current, *start, *next;
    current = START;
    start = NULL;
    while (current != NULL) {
        next = current->next;
        start = insertionSort(start, current);
        current = next;
    }
    START = start;
}


void main()
{
    nd p;
    begin(&p,66);
    end(&p,20);
    begin(&p,70);
    end(&p,25);
    begin(&p,88);
    end(&p,22);
    before(&p,60,66);
    after(&p,30,20);
    delete_after(66);
    begin(&p,50);
    delete_end();
    delete_begin();
    printf("Normal list\n");
    display();
    printf("After sorting\n");
    sort();
    display();
    printf("After reversing\n");
    reverse();
    display();
}
