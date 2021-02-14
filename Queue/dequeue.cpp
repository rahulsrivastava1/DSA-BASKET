// DeQueue

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
int rear=-1,front=-1,queue[MAX];
void insertatrear()
{
	if(front==0 && rear==MAX-1)
		printf("\nOVERFLOW!");
	else
	{
		int val;
		printf("\nEnter value to push:");
		scanf("%d",&val);
		if(front!=0 && rear==MAX-1)
		{
			rear=0;
			queue[rear]=val;
			printf("\ninserted!");
		}
		else if(front==-1 && rear==-1)
		{
			front=0;
			rear=0;
			queue[rear]=val;
			printf("\ninserted!");
		}
		else
		{
			rear=rear+1;
			queue[rear]=val;
			printf("\nInserted!");
		}
	}
}
void insertatfront()
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
			queue[front]=val;
			printf("\ninserted!");
		}
		else if(front==0 && rear!=MAX-1)
		{
			front=MAX-1;
			queue[front]=val;
			printf("\ninserted!");
		}
		else
		{
			front=front-1;
			queue[front]=val;
			printf("\ninserted!");
		}
	}
}
void removeatrear()
{
	if(front==-1 && rear==-1)
		printf("\nUNDERFLOW!");
	else
	{
		if(rear==0)
		{
			printf("\nDeleted value is %d.",queue[rear]);
			rear=MAX-1;
		}
		else if(front==rear)
		{
			printf("\nDeleted value is %d.",queue[rear]);
			rear=-1;
			front=-1;
		}
		else
		{
			printf("\nDeleted value is %d.",queue[rear]);
			rear=rear-1;
		}
	}
}
void removeatfront()
{
	if(front==-1 && rear==-1)
		printf("\nUNDERFLOW!");
	else
	{
		if(front==MAX-1)
		{
			printf("\nDeleted value is %d.",queue[front]);
			front=0;
		}
		else if(front==rear)
		{
			printf("\nDeleted value is %d.",queue[front]);
			rear=-1;
			front=-1;
		}
		else
		{
			printf("\nDeleted value is %d.",queue[front]);
			front=front+1;
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
		printf("\n 1.add at rear 2.add at front 3.delete at rear 4.delete at front 5.display 6.exit");
		printf("\n Enter your choice(1-6):");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insertatrear();
				break;
			case 2:
				insertatfront();
				break;
			case 3:
				removeatrear();
				break;
			case 4:
				removeatfront();
				break;
			case 5:
				display();
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("\nEnter correct choice!");
				break;
		}
		
	}
	return 0;
}
