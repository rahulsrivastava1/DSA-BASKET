// infix to postfix *Reverse polish Notation*

#include<stdio.h>
#include<ctype.h>
char stack[50];
int top =-1;
void push(char elem)
{
	stack[++top]=elem;
}
char pop()
{
	if(top==-1)
		return -1;
	else
		return stack[top--];
}
int precedence(char elem)
{
	if(elem=='(')
		return 0;
	if(elem=='+' || elem=='-')
		return 1;
	if(elem=='*' || elem=='/')
		return 2;
	if(elem=='^')
		return 3;
}
int main()
{
	char infix[50];
	char *e,x;
	printf("Enter infix expression:");
	scanf("%s",&infix);
	e=infix;
	while(*e!='\0')
	{
		if(isalnum(*e))
			printf("%c",*e);
		else if(*e=='(')
			push(*e);
		else if(*e==')')
			while((x=pop())!='(')
				printf("%c",x);
		else
		{
			while(precedence(stack[top])>=precedence(*e))
				printf("%c",pop());
			push(*e);
		}
		e++;	
	}
	while(top!=-1)
		printf("%c",pop());
	return 0;
}

