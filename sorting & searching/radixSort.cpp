// Radix Sort
// Time Complexity :- O(d(n+b))

#include<stdio.h>
#define size 10
int largest(int arr[],int n)
{
	int large=arr[0],i;
	for(i=1;i<n;i++)
	{
		if(arr[i]>large)
			large=arr[i];
	}
	return large;
}
int radixSort(int arr[],int n)
{
	int bucket[size][size],bucket_count[size];
	int i,j,k,remainder,NOP=0,divisor=1,large,pass;
	large=largest(arr,n);
	while(large>0)
	{
		NOP++;
		large /=size;
	}
	for(pass=0;pass<NOP;pass++)
	{
		for(i=0;i<size;i++)
		{
			bucket_count[i]=0;
		}
		for(i=0;i<n;i++)
		{
			remainder=(arr[i]/divisor)%size;
			bucket[remainder][bucket_count[remainder]]=arr[i];
			bucket_count[remainder] +=1;
		}
		i=0;
		for(k=0;k<size;k++)
		{
			for(j=0;j<bucket_count[k];j++)
			{
				arr[i]=bucket[k][j];
				i++;
			}
		}
		divisor *=size;
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
	radixSort(arr,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}

