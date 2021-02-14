// Binary Search in non-recusrive method
// Time complexity :-
// Best Case - O(1)
// Average and worst case - O(logn)

#include<stdio.h>
int binarySearch(int arr[],int first,int last,int s)
{
	if(first<=last)
	{
		int middle;
		middle=(first+last)/2;
		if(arr[middle]==s)
			return middle;
		else if(arr[middle]<s)
			first=middle+1;
		else
			last=middle-1;
	}
	return -1;
}
int main()
{
	int n,s,i,result;
	printf("Enter the size of array:");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements of array in sorted condition:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nEnter the search elements:");
	scanf("%d",&s);
	result=binarySearch(arr,0,n-1,s);
	if(result==-1)
		printf("Element is not found in array.");
	else
		printf("Element is present at index %d.",result);
	return 0;
}
