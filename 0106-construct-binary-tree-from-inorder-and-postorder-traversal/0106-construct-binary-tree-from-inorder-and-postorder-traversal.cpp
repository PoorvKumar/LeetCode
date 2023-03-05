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
class Solution 
{
private:
    unordered_map<int,int> umap;
    
    TreeNode* buildTreeUtil(vector<int>& inorder,vector<int>& postorder,int index,int low,int high)
    {
        if(low>high)
        {
            return NULL;
        }
        
        if(low==high && inorder[low]==postorder[index])
        {
            return new TreeNode(postorder[index]);
        }
        
        TreeNode* root=new TreeNode();
        
        int i=umap[postorder[index]];
        root->val=postorder[index];
        root->right=buildTreeUtil(inorder,postorder,index-1,i+1,high);
        root->left=buildTreeUtil(inorder,postorder,index-1-(high-i),low,i-1);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        for(int i=0; i<inorder.size(); i++)
        {
            umap[inorder[i]]=i;
        }
        
        return buildTreeUtil(inorder,postorder,postorder.size()-1,0,inorder.size()-1);
        //TC: O(n) SC: O(n)
    }
};