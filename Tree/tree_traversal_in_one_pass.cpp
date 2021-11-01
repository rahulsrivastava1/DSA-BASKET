// Only functions
// just storing traversal in separate vectors

vector<int> preInPostOrderTraversal(TreeNode* node){
  stack<pair<TreeNode*,int>> st;
  st.push({root,1});
  vector<int> preorder;
  vector<int> inorder;
  vector<int> postorder;
  if(root==NULL)
    return ;
  while(!st.empty()){
    auto it=st.top();
    st.pop();
    if(it.second==1){
      preorder.push_back(it.first->val);
      it.second++;
      st.push(it);
      if(it.first->left)
        st.push({it.first->left,1});
    }else if(it.second==2){
      inorder.push_back(it.first->val);
      it.second++;
      st.push(it);
      if(it.first->right)
        st.push({it.first->right,1});
    }else{
      postorder.push_back(it.first->val);
    }
  }
}
  
