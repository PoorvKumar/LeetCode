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
    TreeNode* sortedArraytoBSTUtil(vector<int>& nums,int i,int j)
    {
        if(i==j)
        {
            return NULL;
        }
        
        TreeNode* root=new TreeNode(nums[(i+j)/2]);
        root->left=sortedArraytoBSTUtil(nums,i,(i+j)/2);
        root->right=sortedArraytoBSTUtil(nums,(i+j)/2+1,j);
        
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return sortedArraytoBSTUtil(nums,0,nums.size());
    }
};