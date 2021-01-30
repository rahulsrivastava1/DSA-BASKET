// Infix to prefix

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10
int top=-1;
char stack[MAX],infix[MAX],postfix[MAX],inrev[MAX],prefix[MAX];
void push(char elem)
{
	stack[++top]=elem;
}
char pop()
{
	return stack[top--];
}
void reverse(char exp[],char res[])
{
	int i,l;
	l=strlen(exp);
	for(i=0;i<l;i++)
	{
		if(exp[i]=='(')
			res[l-1-i]=')';
		else if(exp[i]==')')
			res[l-1-i]='(';
		else
			res[l-1-i]=exp[i];
	}
	res[i]='\0';
}
int prec(char elem)
{
	if(elem=='(')
		return 0;
	else if(elem=='+' || elem=='-')
		return 1;
	else if(elem=='*' || elem=='/')
		return 2;
	else if(elem=='^')
		return 3;
}
int oprtr(char elem)
{
	if(elem=='^' || elem=='*' || elem=='/' || elem=='+' || elem=='-')
		return 1;
	else
		return 0;
}
void convert(char in[],char pre[])
{ 
  int i,j;
  char k,l;
  push('(');
  strcat(in,")");
  i=0; j=0;
  k=in[i];
  while(k!='\0')
  {
    if(k=='(')
			push(k);
    else if((k>=65 && k<=90) || (k>=97 && k<=122))
			pre[j++]=k;
    else if(oprtr(k)==1)
    {
      l=pop();
      while(oprtr(l)==1 && prec(l)>=prec(k))
			{
				pre[j++]=l;
				l=pop();
			}
      push(l);
      push(k);
    }
    else if(k==')')
    {
      l=pop();
      while(l!='(')
			{
				pre[j++]=l;
				l=pop();
			}
    }
    else
    {
      printf("\nInvalid Infix Expression! [alphabets,(,),+,-,*,/,^ are valid only]");
      exit(0);
    }
    k=in[++i];
  }
  if(top!=-1)
  {
    printf("\nInvalid Infix Expression! [parenthesis are not placed properly]\n");
    exit(0);
  }
  pre[j]='\0';
}
int main()
{
	printf("infix to prefix program.");
	printf("\nEnter infix expression:");
	gets(infix);
	reverse(infix,inrev);
	convert(inrev,postfix);
	reverse(postfix,prefix);
	printf("\nPrefix expressions are:");
	puts(prefix);
	return 0;
}
