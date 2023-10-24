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
    
    void largestValuesUtil(TreeNode* root,int level)
    {
        if(root==NULL)
        {
            return ;
        }
        
        if(!umap.count(level))
        {
            umap[level]=root->val;
        }
        
        umap[level]=max(umap[level],root->val);
        
        largestValuesUtil(root->left,level+1);
        largestValuesUtil(root->right,level+1);
        
        return ;
    }
public:
    vector<int> largestValues(TreeNode* root) 
    {
        largestValuesUtil(root,0);
        
        vector<int> vec(umap.size(),-1);
        
        for(auto x:umap)
        {
            vec[x.first]=x.second;
        }
        
        return vec;
    }
};