// Nearly Sorted Algorithm
// Sort a K-sorted Array
// Time Complexity :- O(NlogK)

#include<bits/stdc++.h>
using namespace std;
void eval(void)
{
    int N,K;
    cin>>N>>K;
    int arr[N];
    for(int i=0;i<N;i++)
        cin>>arr[i];
    priority_queue<int,vector<int>,greater<int>> minH;
    for(int i=0;i<N;i++){
        minH.push(arr[i]);
        if(minH.size()>K){
            cout<<minH.top()<<" ";
            minH.pop();
        }
    }
    while(!minH.empty()){
        cout<<minH.top()<<" ";
        minH.pop();
    }
    cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
        eval();
    return 0;
}
