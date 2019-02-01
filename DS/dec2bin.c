//
//  dec2bin.c
//  
//
//  Created by Kevlyn Kadamala on 14/12/18.
//

#include <stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int arr[10], top;
}stk;

void init(stk *s){
    s->top = -1;
}

void push(stk *s, int ele)
{
    if(s->top == 9){
        printf("Stack overflow\n");
    }
    else{
        s->arr[++s->top] = ele;
    }
}

int pop(stk *s){
    if(s->top == -1){
        printf("Stack underflow\n");
        return -1;
    }
    else{
        return s->arr[s->top--];
    }
}

void main()
{
    int num, temp;
    stk s;
    init(&s);
    printf("Enter a decimal number\n");
    scanf("%d", &num);
    temp = num;
    while(temp != 0){
        push(&s, temp%2);
        temp = temp/2;
    }
    printf("Binary number is\n");
    while(s.top != -1){
        printf("%d ", pop(&s));
    }
    printf("\n");
}
