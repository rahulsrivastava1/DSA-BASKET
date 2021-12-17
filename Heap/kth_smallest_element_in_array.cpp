// Kth Smallest Element in Array
// Time Complexity :- O(NlogK)

#include<bits/stdc++.h>
using namespace std;

// function
int kthsmallest(int arr[],int n){
  priority_queue<int> maxH;
  for(int i=0;i<n;i++){
    maxH.push(arr[i]);
    if(maxH.size()>k)
      maxH.pop();
  }
  return maxH.top();
}

// driver code
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int ans=kthsmallest(arr,n);
  cout<<ans;
  return 0;
}
