// Cycle detection in directed graph
// using bfs

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
bool isCycle(vector<int> adj[],int V){
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
  int count=0;
  while(!q.empty()){
    int node=q.front();
    q.pop();
    count++;
    for(auto it:adj[node]){
      indegree[it]--;
      if(indegree[it]==0)
        q.push(it);
    }
  }
  if(count==V)
    return false;
  return true;
}
};

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
