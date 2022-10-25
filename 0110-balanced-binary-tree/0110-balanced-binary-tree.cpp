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
    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        return max(1+height(root->left),1+height(root->right));
    }
public:
    bool isBalanced(TreeNode* root) 
    {
        if(root==NULL)
        {
            return true;
        }
        
        int x=abs(height(root->left)-height(root->right));
        
        // if(x==0 || x==1)
        // {
        //     return isBalanced(root->left) && isBalanced(root->right);
        // }
        
        return x==0 || x==1?isBalanced(root->left) && isBalanced(root->right):false;
    }
};