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
    int depth(TreeNode* root,int x)
    {
        if(root==NULL)
        {
            return INT_MIN;
        }
        
        if(root->val==x)
        {
            return 0;
        }
        
        return 1+max(depth(root->left,x),depth(root->right,x));
    }
    
    bool isCousinUtil(TreeNode* root,int x,int y)
    {
        if(root==NULL)
        {
            return true;
        }
        
        if(root->left!=NULL && root->right!=NULL)
        {
            if(root->left->val==x && root->right->val==y || root->left->val==y && root->right->val==x)
            {
                return false;
            }
        }
        
        return isCousinUtil(root->left,x,y)&&isCousinUtil(root->right,x,y);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) 
    {        
        if(depth(root,x)==depth(root,y))
        {
            return isCousinUtil(root,x,y);
        }
        
        return false;
    }
};