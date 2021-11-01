// Longest path between two nodes
// Path doesnot need to pass from root node

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
class Solution {
private:
    int height(TreeNode* root,int& diameter){
        if(root==NULL)
            return 0;
        int left=height(root->left,diameter);
        int right=height(root->right,diameter);
        diameter=max(diameter,left+right);
        return max(left,right)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
};
