// Matrix exponentian

// Fast Doubling Methods

#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> matrix;

class Solution{
  public:
  
  matrix multiply(matrix a,matrix b){
    matrix ans(2,vector<int>(2,0));
    for(int i=0;i<a.size();i++){
      for(int j=0;j<b.size();j++){
        for(int k=0;k<b.size();k++)
          ans[i][j]+=a[i][k]*b[k][j];
      }
    }
    return ans;
  }
  
  matrix power(matrix poweredBase,int n){
    if(n==1)
      return poweredBase;
    int half=n/2;
    matrix ans(2,vector<int>(2,0));
    ans=power(poweredBase,half);
    ans=multiply(ans,ans);
    if(n%2==0)
      return ans;
    else{
      ans=multiply(ans,poweredBase);
      return ans;
    }
  }
  
  int findNthTerm(int n){
    if(n==0 || n==1)
      return 1;
    matrix base(2,vector<int>(2,0));
    base[0][0]=base[0][1]=base[1][0]=1;
    base[1][1]=0;
    matrix initial(2,vector<int>(1,0));
    initial[0][0]=initial[0][1]=1;
    matrix poweredBase=power(base,n-1);
    matrix ans=multiply(poweredBase,initial);
    return ans[0][0];
  }
};

int main(){
  int n;
  cin>>n;
  Solution obj;
  int ans=obj.findNthTerm(n);
  cout<<ans;
  return 0;
}
