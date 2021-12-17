// Kth largest Element in Array
// Time Complexity :- O(NlogK)

#include<bits/stdc++.h>
using namespace std;

// function
int kthlargest(int arr[],int n){
  priority_queue<int,vector<int>,greater<int>> minH;
  for(int i=0;i<n;i++){
    minH.push(arr[i]);
    if(minH.size()>k)
      minH.pop();
  }
  return minH.top();
}

// driver code
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int ans=kthlargest(arr,n);
  cout<<ans;
  return 0;
}
