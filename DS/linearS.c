/*
Name: Kevlyn Kadamala
Topic: Implementation of Linear Search Method
Roll no: 8340
*/

#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a[100];
	int x,n,i,flag;
	printf("Enter no of elements:\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter element to be searched\n");
	scanf("%d",&x);
	for(i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			printf("%d is found at location %d\n",x,i);
			flag=1;
			break;
		}
	}
	if(flag!=1)
	printf("%d is not found\n",x);
}

/*
 Enter no of elements:
 8
 Enter the elements
 8
 7
 6
 2
 3
 4
 5
 1
 Enter element to be searched
 2
 2 is found at location 4
 
 Enter no of elements:
 8
 Enter the elements
 8
 4
 5
 6
 7
 2
 3
 1
 Enter element to be searched
 9
 9 is not found
*/
