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
    int sumNumbersUtil(TreeNode* root,int sum)
    {
        if(root==NULL)
        {
            return 0;
        }
        else if(root->left==NULL && root->right==NULL)
        {
            sum=sum*10+root->val;
            return sum;
        }
        else
        {
            sum=sum*10+root->val;
        }
        
        return sumNumbersUtil(root->left,sum)+sumNumbersUtil(root->right,sum);
    }
public:
    int sumNumbers(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        
        return sumNumbersUtil(root,0);
    }
};