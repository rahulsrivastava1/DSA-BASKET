// Stack using linked list :- push,pop and display

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct stack{
	int data;
	struct stack *next;
};
struct stack *top;
void push();
int pop();
void display();
int main()
{
	printf("Stack program using Linked List");
	while(1)
	{
		int option;
		printf("\nMENU");
		printf("\n1.push 2.pop 3.display 4.exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("\nEnter correct choices!");
		}
	}
	return 0;
}
void push()
{
	struct stack *ptr=(struct stack*)malloc(sizeof(struct stack));
	int val;
	printf("Enter the value to push:");
	scanf("%d",&val);
	if(top==NULL)
	{
		ptr->data=val;
		ptr->next=NULL;
		top=ptr;
	}
	else
	{
		ptr->data=val;
		ptr->next=top;
		top=ptr;
	}
}
int pop()
{
	struct stack *ptr;
	if(top==NULL)
		printf("Underflow!");
	else
	{
		ptr=top;
		printf("Deleted value is : %d",ptr->data);
		top=ptr->next;
		free(ptr);
	}
}
void display()
{
	struct stack *ptr;
	if(top==NULL)
		printf("Stack is empty.");
	else
	{
		ptr=top;
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->next;		
		}
		printf("\nTop element is %d",top->data);
	}
}
