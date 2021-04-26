// Binary Search in non-recusrive method
// Time complexity :-
// Best Case - O(1)
// Average and worst case - O(logn)

#include<stdio.h>
int binarySearch(int arr[],int l,int r,int x)
{
	while(r>=l)
	{
		int mid=l+(r-l)/2;
		if(arr[mid]==x)
		{
			return mid;
		}
		else if(arr[mid]<x)
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return -1;
}
int main()
{
	int i,n,arr[50],x;
	printf("\nEnter the size of an array:");
	scanf("%d",&n);
	printf("\nEnter the elements of an array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nEnter the element to search:");
	scanf("%d",&x);
	int result=binarySearch(arr,0,n-1,x);
	if(result==-1)
	{
		printf("\nElement is not present in the array.");
	}
	else
	{
		printf("\nElement is present at index %d",result);
	}
	return 0;
}

