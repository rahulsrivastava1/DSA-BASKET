// Divisors of a number
// sum and count of Divisors

// Time Complexity :-
// for divisors1 fun - O(n)
// for divisors2 fun - O(sqrt(n))


#include <bits/stdc++.h>
using namespace std;

void divisors1(int n){
    int count=0,sum=0;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cout<<i<<endl;
            count++;
            sum+=i;
        }
    }
    cout<<"count :"<<count<<" "<<"sum :"<<sum<<endl;
}

void divisors2(int n){
    int count=0,sum=0;
    for(int i=1;i*i<=n;i++){ // i<=sqrt(n)
        if(n%i==0){
            cout<<i<<" "<<n/i<<endl;
            count++;
            sum+=i;
            if(n/i!=i){
                sum+=n/i;
                count++;
            }
        }
    }
    cout<<"count :"<<count<<" "<<"sum :"<<sum<<endl;
}

int main() {
    int n;
    cin>>n;
    divisors1(n);
    divisors2(n);
	return 0;
}
