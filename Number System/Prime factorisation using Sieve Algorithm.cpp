// Prime factorisation using Sieve Algorithm

#include <bits/stdc++.h>
using namespace std;

const int n=1e7+10;
vector<bool> isPrime(n,1);
vector<int> lp(n,0),hp(n,0);

void sieve(){
    isPrime[0]=isPrime[1]=0;
    for(int i=2;i<n;i++){
        if(isPrime[i]==true){
            lp[i]=hp[i]=i; // marking prime
            for(int j=2*i;j<n;j+=i){
                isPrime[j]=0;
                hp[j]=i;
                if(lp[j]==0)
                    lp[j]=i;
            }
        }
    }
}

int main() {
    sieve();
    int num;
    cin>>num;
    vector<int> prime_factors;
    while(num>1){
        int prime_factor=hp[num];
        while(num%prime_factor==0){
            num/=prime_factor;
            prime_factors.push_back(prime_factor);
        }
    }
    for(int factor:prime_factors)
        cout<<factor<<" ";
	return 0;
}
