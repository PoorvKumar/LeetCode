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
public:
    TreeNode* constructMaximumBinaryTree(vector<int> nums) 
    {
        if(nums.size()==0) //Base Case
        {
            return NULL;
        }
        
        TreeNode* root=new TreeNode();
        vector<int>::iterator it=max_element(nums.begin(),nums.end());
        
        root->val=*it;  //Recursive Step
        root->left=constructMaximumBinaryTree(vector<int>(nums.begin(),it));
        root->right=constructMaximumBinaryTree(vector<int>(it+1,nums.end()));
        
        return root;
    }
};