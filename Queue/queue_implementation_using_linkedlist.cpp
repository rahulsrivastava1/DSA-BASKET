// Queue operation using Linked List

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *front,*rear;
void add()
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	int val;
	printf("\nEnter the value to push:");
	scanf("%d",&val);
	ptr->data=val;
	if(front==NULL)
	{
		front=rear=ptr;
		front->next=rear->next=NULL;
		printf("\nValue inserted.");
	}
	else
	{
		rear->next=ptr;
		rear=ptr;
		rear->next=NULL;
		printf("\nInserted.");
	}
}
void remove()
{
	struct node *ptr;
	if(front==NULL)
		printf("\nUnderflow");
	else
	{
		ptr=front;
		printf("\nDeleted value is %d.",ptr->data);
		front=front->next;
		free(ptr);
	}
}
void display()
{
	struct node *ptr;
	ptr=front;
	if(front==NULL)
		printf("\nQueue is empty.");
	else
	{
		printf("\nprinting values is:");
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->next;
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
