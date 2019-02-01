//
//  newpoly.c
//  
//
//  Created by Kevlyn Kadamala on 31/10/18.
//

#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int pow, coef;
    struct node *next;
}nd;

nd *end(nd *start, int pow, int coef)
{
    nd *newnode = (nd *)malloc(sizeof(nd));
    newnode->pow = pow;
    newnode->coef = coef;
    if(start == NULL){
        start = newnode;
        newnode->next = NULL;
    }
    else{
        nd *ptr;
        ptr = start;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->next = NULL;
    }
    return start;
}

nd *read(nd *start)
{
    int pow, coef, check, flag = 1;
    printf("Enter in descending order of power\n");
    while(flag == 1){
        printf("Enter power and coefficient\n");
        scanf("%d %d", &pow, &coef);
        start = end(start, pow, coef);
        printf("Enter -1 to stop, anything else to continue\n");
        scanf("%d", &check);
        if(check == -1){
            flag = 0;
        }
    }
    return start;
}

nd *add(nd *pol1, nd *pol2, nd *poladd)
{
    nd *ptr1, *ptr2;
    ptr1 = pol1;
    ptr2 = pol2;
    while (ptr1 != NULL && ptr2 !=NULL) {
        if(ptr1->pow == ptr2->pow){
            poladd = end(poladd, ptr1->pow, ptr1->coef+ptr2->coef);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->pow < ptr2->pow){
            poladd = end(poladd, ptr2->pow, ptr2->coef);
            ptr2 = ptr2->next;
        }
        else{
            poladd = end(poladd, ptr1->pow, ptr1->coef);
            ptr1 = ptr1->next;
        }
    }
    if(ptr1 == NULL && ptr2 != NULL){
        while(ptr2 != NULL){
            poladd = end(poladd, ptr2->pow, ptr2->coef);
            ptr2 = ptr2->next;
        }
    }
    else{
        while(ptr1 != NULL){
            poladd = end(poladd, ptr1->pow, ptr1->coef);
            ptr1 = ptr1->next;
        }
    }
    return poladd;
}

nd *subtract(nd *pol1, nd *pol2, nd *polsub)
{
    nd *ptr1, *ptr2;
    ptr1 = pol1;
    ptr2 = pol2;
    while (ptr1 != NULL && ptr2 !=NULL) {
        if(ptr1->pow == ptr2->pow){
            polsub = end(polsub, ptr1->pow, ptr1->coef-ptr2->coef);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->pow < ptr2->pow){
            polsub = end(polsub, ptr2->pow, 0-ptr2->coef);
            ptr2 = ptr2->next;
        }
        else{
            polsub = end(polsub, ptr1->pow, ptr1->coef);
            ptr1 = ptr1->next;
        }
    }
    if(ptr1 == NULL && ptr2 != NULL){
        while(ptr2 != NULL){
            polsub = end(polsub, ptr2->pow, 0-ptr2->coef);
            ptr2 = ptr2->next;
        }
    }
    else{
        while(ptr1 != NULL){
            polsub = end(polsub, ptr1->pow, ptr1->coef);
            ptr1 = ptr1->next;
        }
    }
    return polsub;
}

void display(nd *start)
{
    nd *ptr;
    ptr=start;
    if(start == NULL)
        printf("List is empty\n");
    else
    {
        while(ptr!=NULL)
        {
            if(ptr->coef!=0)
            {
                if(ptr->coef>0)
                    printf("+%dx^%d ",ptr->coef, ptr->pow);
                else
                    printf("%dx^%d ",ptr->coef, ptr->pow);
            }
            ptr=ptr->next;
        }
    }
        printf("\n");
}

void main()
{
    nd *poly1, *poly2, *polyadd, *polysub;
    poly1 = poly2 = polyadd = polysub = NULL;
    printf("Enter first polynomial\n");
    poly1 = read(poly1);
    display(poly1);
    printf("Enter second polynomial\n");
    poly2 = read(poly2);
    display(poly2);
    printf("After addition\n");
    polyadd = add(poly1, poly2, polyadd);
    display(polyadd);
    printf("After subtraction\n");
    polysub = subtract(poly1, poly2, polysub);
    display(polysub);
}

/*
 Enter first polynomial
 Enter in descending order of power
 Enter power and coefficient
 5
 6
 Enter -1 to stop, anything else to continue
 1
 Enter power and coefficient
 3
 4
 Enter -1 to stop, anything else to continue
 1
 Enter power and coefficient
 2
 2
 Enter -1 to stop, anything else to continue
 1
 Enter power and coefficient
 1
 -3
 Enter -1 to stop, anything else to continue
 1
 Enter power and coefficient
 0
 3
 Enter -1 to stop, anything else to continue
 -1
 +6x^5 +4x^3 +2x^2 -3x^1 +3x^0
 Enter second polynomial
 Enter in descending order of power
 Enter power and coefficient
 4
 5
 Enter -1 to stop, anything else to continue
 1
 Enter power and coefficient
 3
 -3
 Enter -1 to stop, anything else to continue
 1
 Enter power and coefficient
 2
 2
 Enter -1 to stop, anything else to continue
 1
 Enter power and coefficient
 0
 -1
 Enter -1 to stop, anything else to continue
 -1
 +5x^4 -3x^3 +2x^2 -1x^0
 After addition
 +6x^5 +5x^4 +1x^3 +4x^2 -3x^1 +2x^0
 After subtraction
 +6x^5 -5x^4 +7x^3 -3x^1 +4x^0
 */
