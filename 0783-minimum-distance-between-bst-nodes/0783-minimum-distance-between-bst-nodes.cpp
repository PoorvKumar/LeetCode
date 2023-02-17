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
    vector<int> vec;
    
    void inOrderTrav(TreeNode* root)
    {
        if(root!=NULL)
        {
            inOrderTrav(root->left);
            vec.push_back(root->val);
            inOrderTrav(root->right);
        }
    }
public:
    int minDiffInBST(TreeNode* root) 
    {
        inOrderTrav(root);
        int ans=INT_MAX;
        
        for(int i=1; i<vec.size(); i++)
        {
            ans=min(ans,vec[i]-vec[i-1]);
        }
        
        return ans;
    }
};