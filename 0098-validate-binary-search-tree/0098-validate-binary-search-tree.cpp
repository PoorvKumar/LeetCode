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
    vector<int> preOrder;
    
    void preorderTraversal(TreeNode* root)
    {
        if(root!=NULL)
        {
            preorderTraversal(root->left);
            preOrder.push_back(root->val);
            preorderTraversal(root->right);
        }
    }
public:
    bool isValidBST(TreeNode* root) 
    {
//         if(root==NULL)
//         {
//             return true;
//         }
        
//         if(root->left==NULL && root->right==NULL)
//         {
//             return true;
//         }
        
//         if(root->left==NULL || root->right==NULL)
//         {
//             if(root->left==NULL)
//             {
//                 return root->right->val>root->val && isValidBST(root->right);
//             }
//             else
//             {
//                 return root->left->val<root->val && isValidBST(root->left);
//             }
//         }
        
//         return root->left->val<root->val && root->right->val>root->val && isValidBST(root->left) && isValidBST(root->right);
        
        preorderTraversal(root);
        
        for(int i=1; i<preOrder.size(); i++)
        {
            if(preOrder[i]<=preOrder[i-1])
            {
                return false;
            }
        }
        
        return true;
    }
};