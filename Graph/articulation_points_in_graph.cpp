// Articulation point in Graph
// Time Complexity :- O(N+E)
// Space Complexity :- O(N)

#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int parent,vector<int>& vis,vector<int>& tin,vector<int>& low,int& timer,vector<int> adj[],vector<int>& isArticulation){
  vis[node]=1;
  tin[node]=low[node]=timer++;
  int child=0;
  for(auto it:adj[node]){
    if(it==parent)
      continue;
    if(!vis[it]){
      dfs(it,node,vis,tin,low,timer,adj,isArticulation);
      low[node]=min(low[node],low[it]);
      if(low[it]>=tin[node] && parent!=-1){
        isArticulation[node]=1;
        child++;
      }else{
        low[node]=min(low[node],tin[it]);
      }
    }
  }
  if(parent==-1 && child>1){
    isArticulation[node]=1;ff
  }
}

//driver code
int main(){
  int V,E;
  cin>>V>>E;
  vector<int> adj[V];
  for(int i=0;i<V;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> tin(V,-1);
  vector<int> low(V,-1);
  vector<int> vis(V,0);
  vector<int> isArticulation(V,0);
  int timer=0;
  for(int i=0;i<V;i++){
    if(!vis[i]){
      dfs(i,-1,vis,tin,low,timer,adj,isArticulation);
    }
  }
  for(int i=0;i<V;i++){
    if(isArticulation[i]==1)
      cout<<i<<endl;
  }
  return 0;
}
