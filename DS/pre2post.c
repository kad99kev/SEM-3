//
//  pre2post.c
//  
//
//  Created by Kevlyn Kadamala on 15/12/18.
//

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define SIZE 10

typedef struct stack{
    char arr[SIZE][SIZE];
    int top;
}stk;

void init(stk *s){
    s->top = -1;
}

void push(stk *s, char *n){
    int i = 0;
    if(s->top == SIZE-1){
        printf("Stack overflow\n");
    }
    else{
        i = ++s->top;
        printf("TOP %d\n", i);
        strcpy(s->arr[i], n);
    }
}

char *pop(stk *s){
    char *n;
    if(s->top == -1){
        printf("Stack underflow\n");
    }
    else{
        return s->arr[s->top--];
    }
}

int isOperand(char o){
    if((o>='0' && 0<='9') || (o>='A' && o<='Z')){
        return 1;
    }
    else{
        return 0;
    }
}

void display(stk *p)    //To display contents of stack
{
    int i;
    for(i=p->top; i>=0; i--)
        printf("%s\n", p->arr[i]);
}

void convert(char prefix[]){
    stk s;
    init(&s);
    int i = 0, p;
    char op1[SIZE], op2[SIZE], res[SIZE], temp[SIZE];
    i = strlen(prefix);
    for(p = i-1; p>=0; p--){
        
        //printf("%d %c", p, prefix[p]);
        
        if(isOperand(prefix[p])){
             printf("TEST %d %c\n", p, prefix[p]);
            char c = prefix[p];
            push(&s, &c);
        }
        else{
            strcpy(&op1[0], pop(&s));
            strcpy(&op2[0], pop(&s));
            display(&s);
            strcat(&op1[0], &op2[0]);
            strcat(&op1[0], &prefix[p]);
            strcpy(&res[0], &op1[0]);
            display(&s);
            push(&s, &res[0]);
            display(&s);
        }
    }
    strcpy(&res[0], pop(&s));
    printf("Prefix experssion is\n");
    
    printf("%s\n", res);
}

void main()
{
    char prefix[50];
    printf("Enter prefix expression\n");
    gets(prefix);
    convert(prefix);
    
}

/*
 Enter prefix expression
 warning: this program uses gets(), which is unsafe.
 *-A/BC-/AKL
 TEST 10 L
 TOP 0
 TEST 9 K
 TOP 1
 TEST 8 A
 TOP 2
 L
 
 L
 
 TOP 1
 K    /AKL
 L
 
 Abort trap: 6
 */
