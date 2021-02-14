// Insertion Sort
// Time complexity :- 
// Best Case :- O(n)
// Average Case and worst case :- O(n^2)

#include<stdio.h>
int insertionSort(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<=n;i++)
	{
		temp=a[i];
		for(j=i-1;j>=0;j--)
		{
			if(a[j]>temp)
			{
				a[j+1]=a[j];
			}
			else
				break;
		}
		a[j+1]=temp;
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
	insertionSort(arr,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
