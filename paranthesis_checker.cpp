// paranthesis checker

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10
int top=-1;
int stack[MAX];
void push(char elem)
{
	if(top==MAX-1)
		printf("Can't push.");
	else
	{
		top =top+1;
		stack[top]=elem;
	}
}
char pop()
{
	if(top==-1)
		printf("Empty.");
	else
	{
		return stack[top--];
	}
}
int main()
{
	char exp[MAX],temp;
	int i,flag=1;
	printf("Enter the expression:");
	scanf("%s",&exp);
	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
			push(exp[i]);
		if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
			if(top==-1)
				flag=0;
			else
			{
				temp=pop();
				if(exp[i]==')' && (temp=='{' || temp=='['))
					flag=0;
				if(exp[i]=='}' && (temp=='(' || temp=='['))
					flag=0;
				if(exp[i]==']' && (temp=='(' || temp=='{'))
					flag=0;
			}
	}
	if(top>=0)
		flag=0;
	if(flag==1)
		printf("Valid expression.");
	else
		printf("Invalid expression.");
	return 0;
}
