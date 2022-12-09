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
    void helper(TreeNode* root,int maxim,int minim,int &ans)
    {
        if(root==NULL)
        {
            return ;
        }
        
        maxim=root->val>maxim?root->val:maxim;
        minim=root->val<minim?root->val:minim;
        
        ans=max(ans,abs(maxim-minim));
        
        helper(root->left,maxim,minim,ans);
        helper(root->right,maxim,minim,ans);
    }
public:
    int maxAncestorDiff(TreeNode* root) 
    {
        if(!root)
        {
            return 0;
        }
        
        int ans=0;
        int maxim=INT_MIN;
        int minim=INT_MAX;
        
        helper(root,maxim,minim,ans);
        
        return ans;
    }
};