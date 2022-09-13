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
//     bool PathSum(TreeNode* root,int targetSum)
//     {
//         int sum=0;
        
//         if(root==NULL)
//         {
//             if(targetSum!=0)
//             {
//                 return false;
//             }
//             else
//             {
//                 return true;
//             }
//         }
        
//         sum=root->val;
        
//         return PathSum(root->left,targetSum-sum) || PathSum(root->right,targetSum-sum);
//     }
    
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root==NULL)
        {
            return false;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            if(root->val==targetSum)
            {
                return true;
            }
            return false;
        }
        
        if(root->left==NULL)
        {
            return hasPathSum(root->right,targetSum-root->val);
        }
        
        if(root->right==NULL)
        {
            return hasPathSum(root->left,targetSum-root->val);
        }
        
        return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val);
    }
};