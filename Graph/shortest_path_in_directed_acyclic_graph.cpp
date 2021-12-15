// Shortest Path in DAG

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
  vector<int> distance(int src,int V,vector<int> adj[]){
    
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
    int src;
    cin>>src;
    Solution obj;
    vector<int> ans=obj.distance(src,V,adj);
    for(int i=0;i<ans.size();i++){
      cout<<ans[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
