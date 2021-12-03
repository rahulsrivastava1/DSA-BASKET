// Time Complexity - O(n)
// Space Complexity - O(1)

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

// Preorder
vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* cur=root;
        while(cur!=NULL){
            if(cur->left==NULL){
                preorder.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode* prev=cur->left;
                while(prev->right && prev->right!=cur){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=cur;
                    preorder.push_back(cur->val);
                    cur=cur->left;
                }else{
                    prev->right=NULL;
                    cur=cur->right;
                }
            }
        }
        return preorder;
    }

// Inorder
vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* node=root;
        vector<int> inorder;
        while(node!=NULL){
            if(node->left==NULL){
                inorder.push_back(node->val);
                node=node->right;
            }
            else{
                TreeNode* prev=node->left;
                while(prev->right && prev->right!=node)
                    prev=prev->right;
                if(prev->right==NULL){
                    prev->right=node;
                    node=node->left;
                }
                else{
                    prev->right=NULL;
                    inorder.push_back(node->val);
                    node=node->right;
                }
            }
        }
        return inorder;
    }
