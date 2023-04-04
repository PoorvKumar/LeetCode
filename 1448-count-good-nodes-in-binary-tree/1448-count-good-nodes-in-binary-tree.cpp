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
    int goodNodesUtil(TreeNode* root,int maximNode)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        if(root->val>=maximNode)
        {
            maximNode=max(maximNode,root->val);
            return 1+goodNodesUtil(root->left,maximNode)+goodNodesUtil(root->right,maximNode);
        }
        
        return 0+goodNodesUtil(root->left,maximNode)+goodNodesUtil(root->right,maximNode);
    }
public:
    int goodNodes(TreeNode* root) 
    {
        return goodNodesUtil(root,root->val);
    }
};