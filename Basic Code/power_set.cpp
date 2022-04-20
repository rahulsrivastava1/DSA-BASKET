// power set

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void printAllSubsets(string s){
  int n=s.size();
  string ans="";
  for(int i=1;i<(1<<n);i++){
    for(int j=0;j<n;j++){
      if(i&(1<<j))
        temp+=s[j];
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
      cout<<ans[i];
    cout<<endl;
  }
}

int main(){
  string s;
  cin>>s;
  printAllSubsets(s);
  return 0;
}
