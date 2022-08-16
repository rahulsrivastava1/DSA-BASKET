// print Binary number

#include<bits/stdc++.h>
using namespace std;

int main(){
    int a=15;
    for(int i=10;i>=0;i--)
        cout<<((a>>i)&1);
    return 0;
}
