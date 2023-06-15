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
    unordered_map<int,long long> umap;
    
    void maxLevelSumUtil(TreeNode* root,int level)
    {
        if(root==NULL)
        {
            return ;
        }
        
        umap[level]=umap[level]+root->val;
        
        maxLevelSumUtil(root->left,level+1);
        maxLevelSumUtil(root->right,level+1);
    }
public:
    int maxLevelSum(TreeNode* root) 
    {
        maxLevelSumUtil(root,1);
        
        int res=INT_MAX;
        long long maxim=INT_MIN;
        
        for(auto x:umap)
        {
            if(maxim==x.second)
            {
                res=min(res,x.first);
                continue;
            }
            if(maxim<x.second)
            {
                res=x.first;
                maxim=x.second;
            }
        }
        
        return res;
    }
};