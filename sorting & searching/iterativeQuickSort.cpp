// iterative quick sort
// Time complexity :- O(NlogN)

#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int low,int high){
    int i=low,j=high,pivot=arr[low];
    while(i<=j){
        while(pivot>=arr[i])
            i++;
        while(pivot<arr[j])
            j--;
        if(i<j)
            swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void quickSortIterative(int arr[],int low,int high){
    int stack[high-low+1];
    int top=-1;
    stack[++top]=low;
    stack[++top]=high;
    while(top>=0){
        high=stack[top--];
        low=stack[top--];
        int p=partition(arr,low,high);
        if(p-1>low){
            stack[++top]=low;
            stack[++top]=p-1;
        }
        if(p+1<high){
            stack[++top]=p+1;
            stack[++top]=high;
        }
    }
}

int main() {
	int arr[]={4,3,5,2,1,3,2,3};
    int n=sizeof(arr)/sizeof(*arr);
    quickSortIterative(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
	return 0;
}
