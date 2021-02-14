// Linear Queue implementations using array

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10
int rear=-1,front=-1,queue[MAX];
void add()
{
	int val;
	if(rear==MAX-1)
		printf("\nOverflow!");
	else
	{
		if(front=-1 && rear==-1)
		{
			front=0;
			rear=0;
			printf("\nEnter the value to push:");
			scanf("%d",&val);
			queue[rear]=val;
			printf("\nInserted!");
		}
		else
		{
			printf("\nEnter the value to push:");
			scanf("%d",&val);
			rear=rear+1;
			queue[rear]=val;
			printf("\nInserted!");
		}
	}
}
void remove()
{
	if(front==-1 && rear==-1)
		printf("\nUnderflow!");
	else
	{
		printf("\nDeleted value is:%d",queue[front]);
		front = front+1;
	}
}
void display()
{
	int i;
	if(front==-1 && rear==-1)
		printf("\nQueue is empty.");
	else
	{
		for(i=front;i<=rear;i++)
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
		printf("\n** QUEUE MENU **");
		printf("\n 1.add 2.delete 3.display 4.exit");
		printf("\n Enter your choice(1-4):");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				add();
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
