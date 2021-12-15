// Topological Sort
// Kahn's Algorithm
// using BFS
// Time Complexity :- O(N+E)
// Space Complexity :- O(2N)

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
  vector<int> topologicalSort(int V,vector<int> adj[]){
    queue<int> q;
    vector<int> indegree(V,0);
    for(int i=0;i<V;i++){
      for(auto it:adj[i])
        indegree[i]++;
    }
    for(int i=0;i<indegree.size();i++){
      if(indegree[i]==0)
        q.push(i);
    }
    vector<int> topo;
    while(!q.empty()){
      int node=q.front();
      q.pop();
      topo.push_back(node);
      for(auto it:adj[node]){
        indegree[it]--;
        if(indegree[it]==0)
          q.push(it);
      }
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
