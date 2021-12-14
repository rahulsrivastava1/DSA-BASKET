// Cycle Detection in Undirected Graph

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
  bool checkCycle(int s,int V,vector<int> adj[],vector<int>& vis){
    vector<int> parent(V,-1);
    queue<pair<int,int>> q;
    visited[s]=true;
    q.push({s,-1});
    while(!q.empty()){
      int node=q.front.first;
      int parent=q.front.second;
      q.pop();
      for(auto it:adj[node]){
        if(!vis[it]){
          vis[it]=true;
          q.push({it,node});
        }else if(parent!=it){
          return true;
        }
      }
      return false;
    }
  }
public:
  bool isCycle(int V,vector<int> adj[]){
    vector<int> vis(V,0);
    for(int i=0;i<V;i++){
      if(!vis[i]){
        if(checkCycle(i,V,adj,vis))
          return true;
      }
    }
    return false;
  }
};

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
    bool ans=obj.isCycle(V,adj);
    if(ans)
      cout<<"1"<<endl;
    else
      cout<<"0"<<endl;
  }
  return 0;
}
