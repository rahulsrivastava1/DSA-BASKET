// Interpolation Search
// Time Complexity:-
// Best Case - O(1)
// worst Case - O(N)
// Average Case - O(log log(n))

#include<stdio.h>
int interpolationSearch(int arr[],int n,int s)
{
	int low=0,high=n-1,middle;
	while(low<=high && s>=arr[low] && s<=arr[high])
	{
		if(low==high)
		{
			if(arr[low]==s)
				return low;
			return -1;
		}
		middle=low+((high-low)*(s-arr[low]))/(arr[high]-arr[low]);
		if(arr[middle]==s)
			return middle;
		else if(arr[middle]<s)
			low=middle+1;
		else
			high=middle-1;
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
	result=interpolationSearch(arr,n,s);
	if(result==-1)
		printf("Element is not found in array.");
	else
		printf("Element is present at index %d.",result);
	return 0;
}
