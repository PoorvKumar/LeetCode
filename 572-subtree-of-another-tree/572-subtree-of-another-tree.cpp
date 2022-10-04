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
private:
    bool isSame(TreeNode* root1,TreeNode* root2)
    {
        if(root1==NULL && root2==NULL)
        {
            return true;
        }
        
        if(root1==NULL || root2==NULL)
        {
            return false;
        }
        
        return root1->val==root2->val&&isSame(root1->left,root2->left)&&isSame(root1->right,root2->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(root==NULL && subRoot==NULL)
        {
            return true;
        }
        
        if(root==NULL)
        {
            return false;
        }
        
        if(root->val==subRoot->val)
        {
            return isSame(root,subRoot)||isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
            // return isSubtree(root->left,subRoot->left)&&isSubtree(root->right,subRoot->right);
        }
        else
        {
            return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
        }
    }
};