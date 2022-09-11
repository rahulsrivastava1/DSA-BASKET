// Lowest and Highest Prime using Sieve Algorithm

#include <bits/stdc++.h>
using namespace std;

const int N=1e7+10;
vector<bool> isPrime(n,1);
vector<int> lp(n,0),hp(n,0);

void sieve(int n){
    isPrime[0]=isPrime[1]=0;
    for(int i=2;i<n;i++){
        if(isPrime[1]){
            lp[i]=hp[i]=i; // marking prime
            for(int j=2*i;j<n;j+=i){
                isPrime[j]=0;
                hp[j]=i;
                if(lp[j]==0)
                    lp[j]=i;
            }
        }
    }
    for(int i=1;i<100;i++)
        cout<<lp[i]<<" "<<hp[i];
}

int main() {
    int n;
    cin>>n;
    sieve(n);
	  return 0;
}
