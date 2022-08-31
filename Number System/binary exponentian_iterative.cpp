// Binary Exponentian
// Time Complexity :- O(logn)

#include <bits/stdc++.h>
using namespace std;
const mod=1e9+7;

int binaryExpoIte(int a,int b){
    // if a becomes large,then execute commented line
    // a=binaryExpoIte(2,1024);
    // a%=mod;
    int ans=1;
    while(b){
      if(b&1)
        ans=(ans*1LL*a)%mod;
      a=(a*1LL*a)%mod;
      b>>=1;
    }
    return ans;
}

int main() {
	int a=2,b=3;
	cout<<binaryExpoIte(a,b);
	return 0;
}
