/** 
* Definition for a Binary Tree Node.
* struct TreeNode {
*     int val;
*     TreeNode* left;
*     TreeNode* right;
*     TreeNode(int x): val(x), left(NULL), right(NULL) {}
* };
*/

// code:-
TreeNode* inorderSuccessor(TreeNode* root,TreeNode* p){
  TreeNode* successor=NULL;
  while(root!=NULL){
    if(p->val>=root->val)
      root=root->right;
    else{
      successor=root;
      root=root->left;
    }
  }
  return successor;
}

  
// Time Complexity:- O(H)
