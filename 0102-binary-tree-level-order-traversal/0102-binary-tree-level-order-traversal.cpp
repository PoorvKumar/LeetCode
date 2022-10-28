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
    void levelOrderHelper(TreeNode* root,vector<vector<int>> &vec,int depth)
    {
        if(root==NULL)
        {
            return ;
        }
        
        vec[depth].push_back(root->val);
        
        levelOrderHelper(root->left,vec,depth+1);
        levelOrderHelper(root->right,vec,depth+1);
    }
    
    int depthTree(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        return 1+max(depthTree(root->left),depthTree(root->right));
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> vec(depthTree(root)); //parameterised constructor of class vector with parameter size
        levelOrderHelper(root,vec,0);
        
        return vec;
    }
};