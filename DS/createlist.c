//
//  createlist.c
//  
//
//  Created by Kevlyn Kadamala on 14/12/18.
//

#include <stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}nd;

nd *create(nd *start){
    int info, n, i;
    nd *ptr, *temp;
    printf("Enter number of nodes in list\n");
    scanf("%d", &n);
    ptr = (nd *)malloc(sizeof(nd));
    printf("Enter element\n");
    scanf("%d", &info);
    ptr->info = info;
    ptr->next = NULL;
    start = ptr;
    for(i = 1; i<n; i++){
        temp = (nd *)malloc(sizeof(nd));
        printf("Enter element\n");
        scanf("%d", &info);
        temp->info = info;
        temp->next = NULL;
        ptr->next = temp;
        ptr = temp;
    }
    return start;
}

void print(nd *start){
    nd *ptr;
    ptr = start;
    while(ptr != NULL){
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}

void main(){
    nd *start;
    start = NULL;
    start = create(start);
    print(start);
}
