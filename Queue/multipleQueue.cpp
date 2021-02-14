// Multiple Queue

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10
int rearA=-1,frontA=-1,rearB=MAX,frontB=MAX,queue[MAX];
void insertA()
{
	if(rearA==rearB-1)
		printf("\nOVERFLOW!");
	else
	{
		int val;
		printf("\nEnter value to push:");
		scanf("%d",&val);
		if(rearA==-1 && frontA==-1)
		{
			rearA=0;
			frontA=0;
			queue[rearA]=val;
			printf("\nvalue inserted!");
		}
		else
		{
			rearA++;
			queue[rearA]=val;
			printf("\nvalue inserted!");
		}
	}
}
void insertB()
{
	if(rearA==rearB-1)
		printf("\nOVERFLOW!");
	else
	{
		int val;
		printf("\nEnter value to push:");
		scanf("%d",&val);
		if(rearB==MAX && frontB==MAX)
		{
			rearB=MAX-1;
			frontB=MAX-1;
			queue[rearB]=val;
			printf("\nValue inserted!");
		}
		else
		{
			rearB--;
			queue[rearB]=val;
			printf("\nvalue inserted!");
		}
	}
}
void removeA()
{
	if(frontA==-1)
		printf("\nUNDERFLOW!");
	else
	{
		printf("\nDeleted value is %d.",queue[frontA]);
		frontA++;
		if(frontA>rearA)
		{
			frontA=-1;
			rearA=-1;
		}
	}
}
void removeB()
{
	if(frontB==MAX)
		printf("\nUNDERFLOW!");
	else
	{
		printf("\nDeleted value is %d.",queue[frontB]);
		frontB--;
		if(frontB>rearB)
		{
			frontB=MAX;
			rearB=MAX;
		}
	}
}
void displayA()
{
	int i;
	if(frontA==-1)
		printf("\nQueue A is empty.");
	else
	{
		printf("\nQueue A is:");
		for(i=frontA;i<=rearA;i++)
		{
			printf("%d ",queue[i]);
		}
	}
}
void displayB()
{
	int i;
	if(frontB==MAX)
		printf("\nQueue B is empty.");
	else
	{
		printf("\nQueue B is:");
		for(i=frontB;i>=rearB;i--)
		{
			printf("%d ",queue[i]);
		}
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("** MULTIPLE QUEUE MENU **");
		printf("\n 1.insert at A 2.insert at B 3.delete at A 4.delete at B 5.display A 6.display B 7.exit");
		printf("\n Enter your choice(1-6):");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insertA();
				break;
			case 2:
				insertB();
				break;
			case 3:
				removeA();
				break;
			case 4:
				removeB();
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
				printf("\nEnter correct choice!");
				break;
		}
	}
	return 0;
}
