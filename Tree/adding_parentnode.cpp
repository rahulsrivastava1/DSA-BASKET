queue<BinaryTreeNode<int>* bfsToMapParents(BinaryTreeNode<int>* root,map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> &mp)
{
	queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {	
    	BinaryTreeNode<int>* temp=q.front();
        q.pop();
        if(temp->left){
        	mp[temp->left]=temp;
            q.push(temp->left);
        }
        if(temp->right){
        	mp[temp->right]=temp;
            q.push(temp->right);
        }
    }
    return q;
}
