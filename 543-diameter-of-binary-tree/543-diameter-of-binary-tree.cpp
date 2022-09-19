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
public:
    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        return 1+max(height(root->left),height(root->right));
    }
    
    int diameterOfBinaryTree(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int height_l=height(root->left)-1;
        int height_r=height(root->right)-1;
        
        int diameter=height_l+height_r+2;
        
        // return diameter;
        
        int d_max=max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right));
        
        return max(diameter,d_max);
    }
};