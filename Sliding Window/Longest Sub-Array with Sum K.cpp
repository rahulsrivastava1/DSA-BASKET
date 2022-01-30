// Longest Sub-Array with Sum K

#include<bits/stdc++.h>
using namespace std;

// For positive integers in array
int longestSubArraySumPositive(int arr[],int n,int k){
  int i=0,j=0;
  int sum=0;
  int maxi=INT_MIN;
  while(j<n){
    sum+=arr[j];
    if(sum<k)
      j++;
    else if(sum==k){
      maxi=max(maxi,j-i+1);
      j++;
    }else if(sum>k){
      while(sum>k){
        sum-=A[i];
        i++;
      }
      j++;
    }
    return maxi;
}

  
// For Positive and Negative integers in array
int longestSubArraySumPositiveandNegative(int arr[],int n,int k){
  int sum=0;
  int maxi=0;
  unordered_map<int,int> mp;
  for(int i=0;i<n;i++){
    sum+=arr[i];
    if(sum==k)
      maxi=max(maxi,i+1);
    if(mp.find(sum)==mp.end())
      mp[sum]=i;
    if(mp.find(sum-k)!=mp.end())
      maxi=max(max,i-mp[sum-k]);
  }
  return maxi;
}
  

int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int k;
  cin>>k;
  cout<<longestSubArraySumPositive(arr,n,k);
  cout<<longestSubArraySumPositiveandNegative(arr,n,k);
  return 0;
}
