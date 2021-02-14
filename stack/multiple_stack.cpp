// Multiple stack

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10
int stack[MAX],topA=-1,topB=MAX;
void pushA()
{
	if(topA==topB-1)
		printf("Overflow!");
	else
	{
		int val;
		printf("Enter the value to push:");
		scanf("%d",&val);
		topA +=1;
		stack[topA]=val;
		printf("\nValue pushed.");
	}
}
void pushB()
{
	if(topB-1==topA)
		printf("Overflow!");
	else
	{
		int val;
		printf("Enter the value to push:");
		scanf("%d",&val);
		topB -=1;
		stack[topB]=val;
		printf("\nValue pushed.");
	}
}
int popA()
{
	if(topA==-1)
		printf("Underflow!");
	else
	{
		printf("Deleted value is:%d",stack[topA]);
		topA--;
	}
}
int popB()
{
	if(topB==MAX)
		printf("Underflow!");
	else
	{
		printf("Deleted value is:%d",stack[topB]);
		topB++;
	}
}
void displayA()
{
	if(topA==-1)
		printf("Stack A is empty.");
	else
	{
		int i;
		for(i=topA;i>=0;i--)
		{
			printf("%d ",stack[i]);
		}
	}
}
void displayB()
{
	if(topB==MAX)
		printf("Stack B is empty.");
	else
	{
		int i;
		for(i=topB;i<MAX;i++)
		{
			printf("%d ",stack[i]);
		}
	}
}
int main()
{
	printf("Multiple Stack Programs.");
	while(1)
	{
		int option;
		printf("\n*****MENU*****");
		printf("\n1.push in A\n2.push in B\n3.pop from A\n4.pop from B\n5.display A\n6.display B\n7.exit:\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				pushA();
				break;
			case 2:
				pushB();
				break;
			case 3:
				popA();
				break;
			case 4:
				popB();
				break;
			case 5:
				displayA();
				break;
			case 6:
				displayB();
				break;
			case 7:
				exit(0);
				break;
			default:
				printf("\nEnter correct choices.");
		}
	}
	return 0;
}
