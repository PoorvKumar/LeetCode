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
    void leafSimilarUtil(TreeNode* root,vector<int>& vec)
    {
        if(root==NULL)
        {
            return;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            vec.push_back(root->val);
        }
        
        leafSimilarUtil(root->left,vec);
        leafSimilarUtil(root->right,vec);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        vector<int> vec1;
        vector<int> vec2;
        
        leafSimilarUtil(root1,vec1);
        leafSimilarUtil(root2,vec2);
        
        return vec1==vec2;
    }
};