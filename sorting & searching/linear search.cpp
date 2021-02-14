// Linear Search
// Time Complexity:-
// Best Case - O(1)
// Average and worst Case - O(N)

#include<stdio.h>
int linearSearch(int arr[],int n,int s)
{
	int j;
	for(j=0;j<n;j++)
	{
		if(arr[j]==s)
			return j;
	}
	return -1;
}
int main()
{
	int n,s,i,result;
	printf("Enter the size of array:");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements of array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nEnter the search elements:");
	scanf("%d",&s);
	result=linearSearch(arr,n,s);
	if(result==-1)
		printf("Element is not found in array.");
	else
		printf("Element is present at index %d.",result);
	return 0;
}
