// only function
// The function will return vector of vectors containing level order traversal nodes

// Time Complexity:- O(N)
// Space Complexity:- O(N)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

vector<vector<int>> levelOrder(TreeNode* root)
{
  vector<vector<int>> ans;
  if(root==NULL)
    return ans;
  queue<TreeNode*> q;
  q.push(root);
  while(!q.empty())
  {
    int size=q.size();
    vector<int> level;
    for(int j=0;j<size;j++)
    {
      TreeNode* temp=q.front();
      q.pop();
      if(temp->left)
        q.push(temp->left);
      if(temp->right)
        q.push(temp->right);
      level.push(temp->val);
    }
    ans.push(level);
  }
  return ans;
}
    
  
