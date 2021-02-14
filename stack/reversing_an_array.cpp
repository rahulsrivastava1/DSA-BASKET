// reversing an array

#include<stdio.h>
int main()
{
	int i,j,n;
	printf("Enter the length of an array:");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter an array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nReversed array is:");
	for(j=n-1;j>=0;j--)
	{
		printf("%d ",arr[j]);
	}
}
