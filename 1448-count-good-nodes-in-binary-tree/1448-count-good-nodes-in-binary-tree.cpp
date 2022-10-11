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
    int goodNodesUtil(TreeNode* root,int MAX)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        MAX=max(MAX,root->val);
        
        if(root->val<MAX)
        {
            return goodNodesUtil(root->left,MAX)+goodNodesUtil(root->right,MAX);
        }
        
        return 1+goodNodesUtil(root->left,MAX)+goodNodesUtil(root->right,MAX);
    }
public:
    int goodNodes(TreeNode* root)
    {
        int MAX=root->val;
        
        return goodNodesUtil(root,MAX);
    }
};