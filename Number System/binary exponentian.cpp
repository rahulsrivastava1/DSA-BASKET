// Binary Exponentian

#include <bits/stdc++.h>
using namespace std;

int binaryExpoRec(int a,int b){
    if(b==0)
        return 1;
    int res=binaryExpoRec(a,b/2);
    if(b&1)
        return a*res*res;
    else
        return res*res;
}

int main() {
	int a=2,b=3;
	cout<<binaryExpoRec(a,b);
	return 0;
}
