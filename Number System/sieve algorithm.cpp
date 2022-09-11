// Prime Factorisation
// Sieve Algorithm

// Time Complexity :- O(nlog(log(n)))

#include <bits/stdc++.h>
using namespace std;

const int n=1e7+10;
vector<bool> isPrime(n,1);

void sieve(){
    isPrime[0]=isPrime[1]=0;
    for(int i=2;i<n;i++){
        if(isPrime[1]){
            for(int j=2*i;j<n;j+=i)
                isPrime[j]=0;
        }
    }
}

int main() {
    int n;
    cin>>n;
    sieve();
    return 0;
}
