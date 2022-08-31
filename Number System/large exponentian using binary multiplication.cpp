// Large exponentian using binary multiplication
// Time Complexity :- O(logn^2)
// if m is large

#include <bits/stdc++.h>
using namespace std;
const long long int mod=1e18+7;

int binaryExpoIte(long long int a,long long int b){
    int ans=1;
    while(b){
      if(b&1)
        ans=binaryMul(a,a);
      a=binaryMul(a,a);
      b>>=1;
    }
    return ans;
}

int binaryMul(long long int a,ling long int b){
  int ans=0;
  while(b){
    if(b&1)
      ans=(ans+a)%mod;
    a=(a+a)%mod;
    b>>=1;
  }
  return ans;
}

int main() {
	int a=2,b=3;
	cout<<binaryExpoIte(a,b);
	return 0;
}
