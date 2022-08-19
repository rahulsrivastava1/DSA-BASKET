// Binary Exponentian

#include <bits/stdc++.h>
using namespace std;

int binaryExpoIte(int a,int b){
    int ans=1;
    while(b){
        ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}

int main() {
	int a=2,b=3;
	cout<<binaryExpoIte(a,b);
	return 0;
}
