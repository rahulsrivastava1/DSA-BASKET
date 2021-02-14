// Circular Queue

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
int rear=-1,front=-1,queue[MAX];
void insert()
{
	if(front==0 && rear==MAX-1)
		printf("\nOVERFLOW!");
	else
	{
		int val;
		printf("\nEnter value to push:");
		scanf("%d",&val);
		if(front==-1 && rear==-1)
		{
			front=0;
			rear=0;
			queue[rear]=val;
			printf("\ninserted!");
		}
		else if(front!=0 && rear==MAX-1)
		{
			rear=0;
			queue[rear]=val;
			printf("\ninserted!");
		}
		else
		{
			rear=rear+1;
			queue[rear]=val;
			printf("\ninserted!");
		}
	}
}
void remove()
{
	if(front==-1)
		printf("\nUNDERFLOW!");
	else
	{
		if(front==rear)
		{
			printf("\nDeleted value is %d.",queue[front]);
			front=-1;
			rear=-1;
		}
		else if(front==MAX-1)
		{
			printf("\nDeleted value is %d",queue[front]);
			front=0;
		}
		else
		{
			printf("\nDeleted value is %d",queue[front]);
			front =front+1;
		}
	}
}
void display()
{
	int i;
	if(front==-1 && rear==-1)
		printf("\nQueue is empty.");
	else
	{
		if(front<rear)
		{
			for(i=front;i<=rear;i++)
			{
				printf("%d ",queue[i]);
			}
		}
		else
		{
			for(i=front;i<MAX;i++)
 				printf("%d ",queue[i]);
			for(i=0;i<=rear;i++)
 				printf("%d ",queue[i]);
		}
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n** QUEUE MENU **");
		printf("\n 1.add 2.delete 3.display 4.exit");
		printf("\n Enter your choice(1-4):");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				remove();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("\nEnter correct choice!");
				break;
		}
		
	}
	return 0;
}
