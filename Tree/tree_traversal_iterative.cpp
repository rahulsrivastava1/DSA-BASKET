// only function

// PreOrder Traversal
vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* temp=st.top();
            ans.push_back(temp->val);
            st.pop();
            if(temp->right)
                st.push(temp->right);
            if(temp->left)
                st.push(temp->left);
        }
        return ans;
    }


// InOrder Traversal
vector<int> inOrderTraversall(TreeNode* root){
  stack<TreeNode*> st;
  TreeNode* node=root;
  vector<int> ans;
  while(true){
    if(node!=NULL){
      st.push(node);
      node=node->left;
    }else{
      if(st.empty()==true)
        break;
      node=st.top();
      st.pop();
      ans.push_back(node->val);
      node=node->right;
    }
  }
  return ans;
}

// PostOrder Traversal using 2 stacks
vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(root);
        while(!st1.empty()){
            root=st1.top();
            st1.pop();
            st2.push(root);
            if(root->left)
                st1.push(root->left);
            if(root->right)
                st1.push(root->right);
        }
        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }

// PostOrder Traversal using 1 stack
vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* curr=root;
        vector<int> ans;
        stack<TreeNode*> st;
        while(curr!=NULL || !st.empty()){
            if(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }else{
                TreeNode* temp=st.top()->right;
                if(temp==NULL){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && temp==st.top()->right){
                        temp=st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }else
                    curr=temp;
            }
        }
        return ans;
    }
