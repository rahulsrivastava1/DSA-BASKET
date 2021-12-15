// Cycle detection in directed graph
// using dfs

#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int node,vector<int> adj[],int vis[],int dfsVis[]){
  vis[node]=1;
  dfsVis[node]=1;
  for(auto it:adj[node]){
    if(!vis[it]){
      if(checkCycle(it,adj,vis,dfsVis)
         return true;
    }else if(vis[it]==dfsVis[it])
         return true;
  }
  dfsVis[node]=0;
  return false;
}

bool isCycle(vector<int> adj[],int V){
  int vis[V];
  int dfsVis[V];
  memset(vis,0,sizeof vis);
  memset(dfsVis,0,sizeof dfsVis);
  for(int i=0;i<V;i++){
    if(!vis[i]){
      if(checkCycle(i,adj,vis,dfsVis)
         return true;
    }
  }
  return false;
}

// driver code
int main(){
  int tc;
  cin>>tc;
  while(tc--){
    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i=0;i<E;i++){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
    }
    if(isCycle(adj,V))
      cout<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
  return 0;
}
