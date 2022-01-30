// Longest K unique characters substring

#include<bits/stdc++.h>
using namespace std;

int longestkUniquechar(string s,int n,int k){
  int i=0,j=0,maxi=-1;
  unordered_map<char,int> mp;
  while(j<n){
    mp[s[j]]++;
    if(mp.size()<k)
      j++;
    else if(mp.size()==k){
      maxi=max(maxi,j-i+1);
      j++;
    }else if(mp.size()==k){
      while(mp.size()>k){
        mp[s[i]]--;
        if(mp[s[i]]==0)
          mp.erase(s[i]);
        i++;
      }
      j++;
    }
  }
  return maxi;
}

int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  int k;
  cin>>k;
  cout<<longestkUniquechar(s,n,k);
  return 0;
}
