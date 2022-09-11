// Large exponentiation with ETF and Euler’s Theorem
// when b is large
// Ex - 50^64^32

#include<bits/stdc++.h>
using namespace std;
cont int M = 1e9+7;

int binExp(int a,long long b,int m){
  int ans=1;
  while(b>0){
    if(b&1)
      ans=(ans*1LL*a)%m;
    a=(a*1LL*a)%m;
    b>>=1;
  }
  return ans;
}

int main(){
  cout<<binExp(50,binExp(64,32,M-1),M);
return 0;
}
