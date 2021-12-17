// Bellman Ford Algorithm
// Time Complexity :- O(N-1)*O(E)
// Space Complexity :- O(N)

// It helps us to detect negative edge cycle in Graph

#include<bits/stdc++.h>
using namespace std;

struct node{
  int u,v,wt;
  node(int x,int y,int z){
    u=x;
    v=y;
    z=wt;
  }
};

// driver code
int main(){
  int tc;
  cin>>tc;
  while(tc--){
    int V,E;
    cin>>V>>E;
    vector<node> edges;
    for(int i=0;i<V;i++){
      int u,v,wt;
      cin>>u>>v>>wt;
      edges.push_back(node(u,v,wt));
    }
    int src;
    cin>>src;
    vector<int> dist(V,INT_MAX);
    dist[src]=0;
    
    // Relaxing N-1 times
    for(int i=1;i<V-1;i++){
      for(auto it:edges){
        if(dist[it.u]+it.wt<dist[it.v])
          dist[it.v]=dist[it.u]+it.wt
      }
    }
    
    // for checking negative cycles
    int fl=0;
    for(auto it:edges){
      if(dist[it.u]+it.wt<dist[it.v]){
        cout<<"Negative Cycles.";
        fl=1;
        break;
      }
    }
    
    // printing shortest distance if there is no any negative cycles in graph
    if(!fl){
      for(int i=0;i<V;i++){
        cout<<i<<" "<<dist[i]<<endl;
      }
    }
    
  }
  return 0;
}
