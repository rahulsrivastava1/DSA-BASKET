// Topological Sort
// Time Complexity :- O(N+E)
// Space Complexity :- O(3N)

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
void findTopoSort(int node,vector<int> adj[],vector<int>& vis,stack<int>& st){
  vis[node]=1;
  for(auto it:adj[node]){
    if(!vis[it]){
      findTopoSort(it,adj,vis,st);
    }
  }
  st.push(node);
}
  
public:
  vector<int> topologicalSort(int V,vector<int> adj[]){
    stack<int> st;
    vector<int> vis(V,0);
    for(int i=0;i<V;i++){
      if(vis[i]==0)
        findTopoSort(i,adj,vis,st);
    }
    vector<int> topo;
    while(!st.empty()){
      topo.push_back(st.top());
      st.pop();
    }
    return topo;
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
    vector<int> ans=obj.topologicalSort(V,adj);
    for(int i=0;i<ans.size();i++){
      cout<<ans[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
