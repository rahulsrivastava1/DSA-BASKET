// QuickSort using Dutch National Flag Algorithm

// Quicksort exhibits poor performance for inputs that contain many repeated elements. The problem is visible when all the input elements are equal. 
// Then at each point in recursion, the left partition is empty (no input values are less than the pivot), and the right partition has only decreased 
// by one element (the pivot is removed). Consequently, the algorithm takes quadratic time to sort an array of equal values.

#include<bits/stdc++.h>
using namespace std;

pair<int,int> partition(vector<int>& arr,int start,int end){
  int mid=start;
  int pivot=arr[end];
  while(mid<=end){
    if(arr[mid]<pivot){
      swap(arr[start],arr[mid]);
      start++;
      mid++;
    }else if(arr[mid]>pivot){
      swap(arr[mid],arr[end]);
      end--;
    }else
      mid++;
  }
  return {start-1,end};
}

void quickSort(vector<int>& arr,int start,int end){
  if(start>=end)
    return;
  if(end-start==1){
    if(arr[start]>arr[end])
      swap(arr[start],arr[end]);
    return;
  }
  pair<int,int> pivot=partition(arr,start,end);
  quickSort(arr,start,pivot.first);
  quickSort(arr,pivot.second,end);
}

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  quickSort(arr,0,n-1);
  for(auto it:arr)
    cout<<it<<" ";
  return 0;
}
