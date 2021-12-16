// Prim's Algorithm in Brute force
// Time Complexity :- >O(N^2)

#include<bits/stdc++.h>
using namespace std;
int main(){
  int V,E;
  cin>>V>>E;
  vector<int> adj[V];
  for(int i=0;i<E;i++){
    int u,v,wt;
    cin>>u>>v>>wt;
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
  }
  int key[V];
  bool mst[V];
  int parent[V];
  for(int i=0;i<V;i++){
    key[i]=INT_MAX;
    mst[i]=false;
    parent[i]=-1;
  }
  key[0]=0;
  // for V-1 edges
  for(int count=0;count<V-1;count++){
    int mini=INT_MAX,u;
    for(int j=0;j<V;j++){
      if(mst[j]==false && key[j]<mini)
        mini=key[j],u=j;
    }
    mst[u]=true;
    for(auto it:adj[u]){
      int v=it.first;
      int weight=it.second;
      if(mst[v]==false && weight<key[v])
        parent[v]=u,key[v]=weight;
    }
  }
  // printing
  for(int i=0;i<V;i++)
    cout<<parent[i]<<" - "<<i<<endl;
  return 0;
}
