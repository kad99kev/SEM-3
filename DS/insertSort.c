//
//  insertSort.c
//  
//
//  Created by Kevlyn Kadamala on 15/12/18.
//

#include <stdio.h>
#include<stdlib.h>

void insertSort(int list[]){
    int i, j, ele;
    for(i = 1; i < 5; i++){
        j = i-1;
        ele = list[i];
        while((j >= 0) && (list[j] > ele)){
            list[j+1] = list[j];
            j--;
        }
        list[j+1] = ele;
    }
}

void main(){
    int a[5];
    printf("Enter 5 numbers\n");
    for(int i = 0; i < 5; i++){
        scanf("%d", &a[i]);
    }
    insertSort(a);
    printf("List after sorting is\n");
    for(int i = 0; i < 5; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

/*
 Enter 5 numbers
5
4
3
2
1
List after sorting is
1 2 3 4 5
*/
