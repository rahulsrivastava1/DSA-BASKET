// Prim's Algorithm in Efficient way
// Time Complexity :- O((N+E)logN)
// Space Complexity :- O(3N) for 3 arrays

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
  }
  key[0]=0;
  parent[0]=-1;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  pq.push({0,0});
  for(int i=0;i<V-1;i++){
    int node=pq.top().second;
    pq.pop();
    mst[node]=true;
    for(auto it:adj[node]){
      int v=it.first;
      int weight=it.second;
      if(mst[v]==false && weight<key[v]){
        parent[v]=node;
        pq.push({key[v],v});
        key[v]=weight;
      }
    }
  }
  for(int i=0;i<V;i++){
    cout<<parent[i]<<" - "<<i<<endl;
  }
  return 0;
}
