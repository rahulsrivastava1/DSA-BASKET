// Fibonnaci Search

#include<stdio.h>
int min(int x,int y)
{
	return x<=y?x:y;
}
int fibonacciSearch(int a[],int s,int n)
{
	int fib2=0;
	int fib1=1;
	int fib=fib2+fib1;
	while(fib<n)
	{
		fib2=fib1;
		fib1=fib;
		fib=fib2+fib1;
	}
	int offset=-1;
	while(fib>1)
	{
		int i=min(fib2+offset,n-1);
		if(a[i]<s)
		{
			fib=fib1;
			fib1=fib2;
			fib2=fib-fib1;
			offset=i;
		}
		else if(a[i]>s)
		{
			fib=fib2;
			fib1=fib1-fib2;
			fib2=fib-fib1;
		}
		else
			return i;
	}
		if(fib1 && a[offset+1]==s)
			return offset+1;
		return -1;
}
int main()
{
	printf("Fibonacci Search program");
	int n,i,s,result;
	printf("\nEnter the size of an array:");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements of an array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nEnter the elements to be search:");
	scanf("%d",&s);
	result=fibonacciSearch(arr,s,n);
	if(result==-1)
		printf("\nElement not found in the array.");
	else
		printf("\nElement found at the index %d",result);
	return 0;
}
