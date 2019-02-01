//
//  newcirlink.c
//  
//
//  Created by Kevlyn Kadamala on 15/12/18.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}nd;

nd  *begin(nd *start, int n){
    
    nd *newnode = (nd *)malloc(sizeof(nd));
    newnode->info = n;
    nd *ptr;
    ptr = start;

    if(start == NULL){
        start = newnode;
        newnode->next = start;
    }
    else{
        while(ptr->next != start){
            ptr = ptr->next;
        }
        newnode->next = start;
        ptr->next = newnode;
        start = newnode;
    }
    return start;
}

nd *end(nd *start, int n){
    
    nd *newnode = (nd *)malloc(sizeof(nd));
    newnode->info = n;
    nd *ptr;
    ptr = start;
    
    if(start == NULL){
        start = newnode;
        newnode->next = start;
    }
    else{
        while(ptr->next != start){
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->next = start;
    }
    return start;
}

nd *before(nd *start, int n, int b){
    
    nd *newnode = (nd *)malloc(sizeof(nd));
    newnode->info = n;
    nd *ptr, *preptr;
    ptr = start;
    
    if(start == NULL){
        printf("List is empty, cannot add before\n");
    }
    else if(start->info == b){
        while(ptr->next != start){
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->next = start;
        start = newnode;
    }
    else{
        while(ptr->info != b && ptr->next!= start){
            preptr = ptr;
            ptr = ptr->next;
        }
        
        if(ptr->info != b && ptr->next == start){
            printf("Node not found\n");
        }
        else{
            preptr->next = newnode;
            newnode->next = ptr;
        }
    }
    return start;
}

nd *after(nd *start, int n, int a){
    
    nd *newnode = (nd *)malloc(sizeof(nd));
    newnode->info = n;
    nd *ptr;
    ptr = start;
    
    if(start == NULL){
        printf("List is empty, cannot add after\n");
    }
    else{
        while(ptr->info != a && ptr->next!= start){
            ptr = ptr->next;
        }
        
        if(ptr->info != a && ptr->next == start){
            printf("Node not found\n");
        }
        else{
            newnode->next = ptr->next;
            ptr->next = newnode;
        }
        
    }
    return start;
}

nd *delete(nd *start, int n){
    
    nd *ptr, *preptr;
    ptr = start;
    
    if(start == NULL){
        printf("List empty\n");
    }
    else if(start->info == n && start->next == start){
        printf("Deleted info %d\n", start->info);
        free(ptr);
        start = NULL;
    }
    else if(start->info == n && start->next != start){
        while(ptr->next != start){
            ptr = ptr->next;
        }
        printf("Deleted info %d\n", start->info);
        ptr->next = start->next;
        preptr = start;
        start = start->next;
        free(preptr);
    }
    else{
        while(ptr->info != n && ptr->next != start){
            preptr = ptr;
            ptr = ptr->next;
        }
        
        if(ptr->info != n && ptr->next == start){
            printf("Node not found\n");
        }
        else{
            printf("Deleted info %d\n", ptr->info);
            preptr->next = ptr->next;
            free(ptr);
        }
    }
    return start;
}

nd *delete_bef(nd *start, int b){
    nd *ptr, *preptr, *prepre;
    ptr = start;
    if(start == NULL){
        printf("List empty\n");
    }
    else if(start->info == b && start->next == start){
        printf("Deleted info %d\n", start->info);
        free(ptr);
        start = NULL;
    }
    else if(start->info == b && start->next != start){
        while(ptr->next != start){
            preptr = ptr;
            ptr = ptr->next;
        }
        printf("Deleted info %d\n", start->info);
        preptr->next = ptr->next;
        free(ptr);
    }
    else{
        while(ptr->info !=b && ptr->next != start){
            prepre = preptr;
            preptr = ptr;
            ptr = ptr->next;
        }
        
        if(ptr->info != b && ptr->next == start){
            printf("Node not found\n");
        }
        else{
            prepre->next = ptr;
            printf("Deleted info %d\n", preptr->info);
            free(preptr);
        }
    }
    return start;
}

nd *delete_after(nd *start, int a){
    
    nd *ptr, *temp;
    ptr = start;
    
    if(start == NULL){
        printf("List empty\n");
    }
    else if(start->info == a && start->next == start){
        printf("Deleted info %d\n", start->info);
        free(start);
        start = NULL;
    }
    else{
        while(ptr->info != a && ptr->next != start){
            ptr = ptr->next;
        }
        
        if(ptr->info != a && ptr->next == start){
            printf("Node not found\n");
        }
        else if(ptr->info == a && ptr->next == start){
            printf("Deleted info %d\n", start->info);
            temp = start;
            ptr->next = start->next;
            start = start->next;
            free(temp);
        }
        else{
            temp = ptr->next;
            ptr->next = temp->next;
            printf("Deleted info %d\n", temp->info);
            free(temp);
        }
    }
    return start;
}

void display(nd *start){
    nd *ptr;
    ptr = start;
    printf("Elements in the list are\n");
    if(start == NULL){
        printf("List is empty\n");
    }
    else{
        do{
            printf("%d ", ptr->info);
            ptr = ptr->next;
        }while(ptr != start);
        printf("\n");
    }
}

void main(){
    nd *start;
    start = NULL;
    start = after(start, 10, 20);
    start = before(start, 10, 30);
    start = begin(start, 10);
    start = end(start, 50);
    start = begin(start, 70);
    start = end(start, 20);
    start = begin(start, 30);
    start = end(start, 40);
    start = delete(start, 10);
    start = after(start, 90, 20);
    start = delete_bef(start, 50);
    start = before(start, 80, 30);
    start = delete_after(start, 50);
    start = begin(start, 120);
    display(start);
    
}
