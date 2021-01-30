// prefix evaluation

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
int top=-1;
int stack[50];
char temp[50];
void push(char elem)
{
	stack[++top]=elem;
}
int pop()
{
	return stack[top--];
}
int get_type(char c)
{
	if(c=='+' || c=='-' || c=='*' || c=='/')
		return 1;
	else
		return 0;
}
int main()
{
	char prefix[50];
	printf("Enter prefix expression:");
	scanf("%s",&prefix);
	int i,a,b,r,val;
	int len=strlen(prefix);
	for(i=len-1;i>=0;i--)
	{
		switch(get_type(prefix[i]))
		{
			case 0:
				val=prefix[i]-'0';
				push(val);
				break;
			case 1:
				a=pop();
				b=pop();
				switch(prefix[i])
				{
				case '+':
					r=a+b;
					break;
				case '-':
					r=a-b;
					break;
				case '*':
					r=a*b;
					break;
				case '/':
					r=a/b;
					break;
				}
				push(r);
		}
	}
	printf("%d",stack[0]);
	return 0;	
}
