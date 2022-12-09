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
    int maxVal(TreeNode* root,int maximVal)
    {
        if(root==NULL)
        {
            return maximVal;
        }
        
        maximVal=max(maximVal,root->val);
        maximVal=max(maximVal,maxVal(root->left,maximVal));
        
        return max(maximVal,maxVal(root->right,maximVal));
    }
    
    int minVal(TreeNode* root,int minimVal)
    {
        if(root==NULL)
        {
            return minimVal;
        }
        
        minimVal=min(minimVal,root->val);
        minimVal=min(minimVal,minVal(root->left,minimVal));
        
        return min(minimVal,minVal(root->right,minimVal));
    }
public:
    int maxAncestorDiff(TreeNode* root,int maximDiff=0) 
    {
        if(root==NULL) //Base Case
        {
            return maximDiff;
        }
        
        int minimVal=min(minVal(root->left,root->val),minVal(root->right,root->val));
        int maximVal=max(maxVal(root->left,root->val),maxVal(root->right,root->val));
        // cout<<minimVal<<endl;
        // cout<<maximVal<<endl;
        
        maximDiff=max(abs(root->val-minimVal),abs(root->val-maximVal));
        maximDiff=max(maximDiff,maxAncestorDiff(root->left,maximDiff));
        
        return max(maximDiff,maxAncestorDiff(root->right,maximDiff));
    }
};