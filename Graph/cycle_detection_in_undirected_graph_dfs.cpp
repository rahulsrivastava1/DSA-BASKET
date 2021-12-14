// Cycle detection in undirected graph 
// using dfs

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
  bool isCycleDetect(int node,int parent,vector<int>& vis,vector<int> adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
      if(vis[it]==0){
        if(isCycleDetect(it,node,vis,adj))
           return true;
      }else{
        if(it!=parent)
          return true;
      }
    }
    return false;
  }
public:
  bool isCycle(int V,vector<int> adj[]){
    vector<int> visited[V];
    for(int i=0;i<V;i++){
      if(!visited[i]){
        if(isCycleDetect(i,-1,vis,adj))
          return true;
      }
      return false;
  }
};

// driver code
int main(){
  int component;
  cin>>component;
  while(component--){
    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i=0;i<E;i++){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    Solution obj;
    bool ans=isCycle(V,adj);
    if(ans)
      cout<<"True"<<endl;
    else
      cout<<"False"<<endl;
  }
  return 0;
}
      
