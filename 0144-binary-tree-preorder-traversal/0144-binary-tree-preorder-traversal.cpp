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
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> vec;
        // vector<int> subtree;
        
        if(root)
        {
            vec.push_back(root->val);
            vector<int> subtree=preorderTraversal(root->left);
            for(auto x:subtree)
            {
                vec.push_back(x);
            }
            
            subtree=preorderTraversal(root->right);
            for(auto x:subtree)
            {
                vec.push_back(x);
            }
        }
        
        return vec;
    }
};