// Bubble Sort
// Time complexity :- O(n^2)

#include<stdio.h>
int bubbleSort(int arr[],int n)
{
	int i,j,temp;
	for(i-0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
int main()
{
	int n,i;
	printf("Enter the size of array:");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements of an array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nSorted array is:");
	bubbleSort(arr,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
