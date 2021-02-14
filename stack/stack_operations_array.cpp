// Stack using array :- push,pop and display

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
int top=-1,arr[MAX];
void push();
int pop();
void display();
int main()
{
	printf("Stack program using array");
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
	if(top==MAX-1)
		printf("\nOverflow!");
	else
	{
		int value;
		printf("Enter the value to push:");
		scanf("%d",&value);
		top=top+1;
		arr[top]=value;
		printf("Value assigned.");
	}
}
int pop()
{
	if(top==NULL)
		printf("\nUnderflow");
	else
	{
		printf("\nDeleted value is: %d",arr[top]);
		top=top-1;
	}
}
void display()
{
	int i;
	if(top==NULL)
		printf("\nStack is empty.");
	else
	{
		for(i=0;i<5;i++)
		{
			printf("%d ",arr[i]);
		}
	}
}
