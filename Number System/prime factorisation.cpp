// Prime Factorisation

// Time Complexity :-
// for prime_factorisation1 fun - O(n)
// for prime_factorisation2 fun - O(sqrt(n))


#include <bits/stdc++.h>
using namespace std;

void prime_factorisation1(int n){
    vector<int> prime_factors;
    for(int i=2;i<=n;i++){
        while(n%i==0){
            prime_factors.push_back(i);
            n/=i;
        }
    }
    for(int prime:prime_factors)
        cout<<prime<<" ";
}

void prime_factorisation2(int n){
    vector<int> prime_factors;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            prime_factors.push_back(i);
            n/=i;
        }
    }
    if(n>1)
        prime_factors.push_back(n);
    for(int prime:prime_factors)
        cout<<prime<<" ";
}

int main() {
    int n;
    cin>>n;
    prime_factorisation1(n);
	return 0;
}
