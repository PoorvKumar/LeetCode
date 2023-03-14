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
    int ans=0;
public:
    int sumNumbers(TreeNode* root,int val=0) 
    {
        if(root==NULL) //base case
        {
            return 0;
        }
        
        if(root->left==NULL && root->right==NULL) //base case
        {
            val=val*10 + root->val;
            ans=ans+val;
            return ans;
        }
        
        val=val*10+root->val;
        
        // return sumNumbers(root->left,val) + sumNumbers(root->right,val);
        sumNumbers(root->left,val);
        sumNumbers(root->right,val);
        
        return ans;
    }
};