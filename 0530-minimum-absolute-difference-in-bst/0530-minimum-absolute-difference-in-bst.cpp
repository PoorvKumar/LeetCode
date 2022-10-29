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
    int getMax(TreeNode* root)
    {
        if(root==NULL)
        {
            return INT_MAX;
        }
        if(root->right!=NULL)
        {
            return getMax(root->right);
        }
        
        return root->val;
    }
    
    int getMin(TreeNode* root)
    {
        if(root==NULL)
        {
            return INT_MAX;
        }
        if(root->left!=NULL)
        {
            return getMin(root->left);
        }
        
        return root->val;
    }
    
    int getMinDiffHelper(TreeNode* root,int &minim)
    {
        if(root==NULL || root->left==NULL && root->right==NULL)
        {
            return minim;
        }
        
        if(root->left==NULL || root->right==NULL)
        {
            int diff;
            if(root->left==NULL)
            {
                diff=getMin(root->right)-root->val;
                minim=min(minim,diff);
                return getMinDiffHelper(root->right,minim);
            }
            else
            {
                diff=root->val-getMax(root->left);
                minim=min(minim,diff);
                return getMinDiffHelper(root->left,minim);
            }
        }
        
        int diff=getMin(root->right)-root->val;
        diff=min(diff,root->val-getMax(root->left));
        
        minim=min(minim,diff);
        
        getMinDiffHelper(root->left,minim);
        getMinDiffHelper(root->right,minim);
        
        return minim;
    }
public:
    int getMinimumDifference(TreeNode* root) 
    {
        int minim=INT_MAX;
        
        getMinDiffHelper(root,minim);
        
        return minim;
    }
};