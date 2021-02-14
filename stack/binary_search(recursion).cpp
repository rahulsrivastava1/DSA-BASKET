// Binary Search as Recursive mode

#include<stdio.h>
int binarySearch(int arr[],int l,int r,int s)
{
	if(l<=r)
	{
		int middle=(l+r)/2;
		if(arr[middle]==s)
			return middle;
		else if(arr[middle]<s)
			return binarySearch(arr,middle+1,r,s);
		else
			return binarySearch(arr,l,middle-1,s);
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
