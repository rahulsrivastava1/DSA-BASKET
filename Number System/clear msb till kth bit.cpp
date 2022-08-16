// clear msb till kth bit

#include<bits/stdc++.h>
using namespace std;

int main(){
    int a=59;
    for(int i=10;i>=0;i--)
        cout<<((a>>i)&1);
    cout<<endl;
    int k=3;
    int b=a&((1<<(k+1))-1);
    for(int i=10;i>=0;i--)
        cout<<((b>>i)&1);
    return 0;
}
