// Longest Substring Without Repeating Characters

#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
  int i=0,j=0,maxi=0;
  unordered_map<char,int> mp;
  while(j<s.size()){
    mp[s[j]]++;
    if(mp.size()==j-i+1){
      maxi=max(maxi,j-i+1);
      j++;
    }else if(mp.size()<j-i+1){
      while(mp.size()<j-i+1){
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
  string s;
  cin>>s;
  cout<<lengthOfLongestSubstring(s);
  return 0;
}
