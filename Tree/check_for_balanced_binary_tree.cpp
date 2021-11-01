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

// Time Complexity : O(n)

int height(TreeNode* root){
  int ans;
  if(root==NULL)
     return 0;
  int left=height(root->left);
  int right=height(root->right);
  if(left==-1 || right==-1)
      return -1;
  if(abs(left-right)>1)
      return -1;
  return 1+max(left,right);
 }
 bool isBalanced(TreeNode* root) {
    int res=height(root);
    if(res==-1)
        return false;
     return true
  }
