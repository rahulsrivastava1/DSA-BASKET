// Postfix evaluation

#include<stdio.h>
#include<conio.h>
#include<ctype.h>
int top=-1;
int stack[50];
void push(char elem)
{
	stack[++top]=elem;
}
int pop()
{
	return stack[top--];
}
int main()
{
	char postfix[50];
	int a,b,r,num;
	char *e;
	printf("Enter postfix expression:");
	scanf("%s",&postfix);
	e=postfix;
	while(*e!='\0')
	{
		if(isdigit(*e))
		{
			num=*e-48;
			push(num);
		}
		else
		{
			a=pop();
			b=pop();
			switch(*e)
			{
				case '+':
					r=b+a;
					break;
				case '-':
					r=b-a;
					break;
				case '*':
					r=b*a;
					break;
				case '/':
					r=b/a;
					break;
			}
			push(r);
		}
		e++;
	}
	printf("%d",pop());
	return 0;
}
