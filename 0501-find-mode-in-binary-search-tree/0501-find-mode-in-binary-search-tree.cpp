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
    
    void traverse(TreeNode* root)
    {
        if(root==NULL)
        {
            return ;
        }
        
        umap[root->val]++;
        
        traverse(root->left);
        traverse(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) 
    {
        traverse(root);
        
        int maxim=0;
        for(auto x:umap)
        {
            maxim=max(x.second,maxim);
        }
        
        vector<int> res;
        
        for(auto x:umap)
        {
            if(x.second==maxim)
            {
                res.push_back(x.first);
            }
        }
        
        return res;
    }
};