/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
private:
    bool searchBT(TreeNode* root,TreeNode* p)
    {
        if(root==p)
        {
            return true;
        }
        
        if(root==NULL)
        {
            return false;
        }
        
        return searchBT(root->left,p) || searchBT(root->right,p);
    }
    
    TreeNode* lcaUtil(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(root==NULL)
        {
            return NULL;
        }
        
        if(root==p || root==q)
        {
            if(root==p)
            {
                return p;
            }
            
            return q;
        }
        
        if(searchBT(root->left,p) && searchBT(root->right,q) || searchBT(root->left,q) && searchBT(root->right,p))
        {
            return root;
        }
        
        TreeNode* res=lcaUtil(root->left,p,q);
        if(res!=NULL)
        {
            return res;
        }
        res=lcaUtil(root->right,p,q);
        return res;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        return lcaUtil(root,p,q);
    }
};