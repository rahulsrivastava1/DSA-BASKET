// Selection Sort
// Time Complexity :- O(n^2)

#include<stdio.h>
int selectionSort(int arr[],int n)
{
	int i,j,temp;
	for(i-0;i<n-1;i++)
	{
		for(j=i+1;j<=n-1;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
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
	selectionSort(arr,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
