// Huffman Encoding
// Time Complexity :- O(NLogN)
// Space Complexity :- O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
  struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
      data=val;
      left=NULL;
      right=NULL;
    }
  };
  
  struct cmp{
    bool operator()(Node* l,Node* r){
      return l->data>r->data;
    }
  };
  
  void preorder(Node* root,string s,vector<string>& ans){
    if(!root)
      return;
    if(!root->left && !root->right)
      ans.push_back(s);
    preorder(root->left,s+"0",ans);
    preorder(root->right,s+"1",ans);
  }
  
  vector<string> huffmanCodes(string s,vector<int> f,int N){
    priority_queue<Node*,vector<Node*>,cmp> pq;
    for(int i=0;i<N;i++){
      Node* temp=new Node(f[i]);
      pq.push(temp);
    }
    while(pq.size()!=1){
      Node* left=pq.top();
      pq.pop();
      Node* right=pq.top();
      pq.pop();
      Node* parent=new Node(left->data+right->data);
      parent->left=left;
      parent->right=right;
      pq.push(parent);
    }
    Node* root=pq.top();
    pq.pop();
    vector<string> ans;
    preorder(root,"",ans);
    return ans;
  }
};


// driver code
int main(){
  int T;
  cin>>T;
  while(T--){
    string s;
    cin>>s;
    int N=s.size();
    vector<int> f(N);
    for(int i=0;i<N;i++){
      cin>>f[i];
    }
    Solution ob;
    vector<string> ans=ob.huffmanCodes(s,f,N);
    for(auto it:ans){
      cout<<i<<" ";
    }
    cout<<"\n";
  }
  return 0;
}
