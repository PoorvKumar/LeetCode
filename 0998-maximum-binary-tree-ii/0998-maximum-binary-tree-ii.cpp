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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) 
    {
        // if(root==NULL)
        // {
        //     return NULL;
        // }
        
        if(root==NULL || root->val<val)
        {
            TreeNode* p=new TreeNode(val);
            p->val=val;
            p->left=root;
            p->right=NULL;
            return p;
        }
        
        //values unique so if(root->val<val==false) is true then root->val>val==true
        //when appended to array aways in right subtree
        
        root->right=insertIntoMaxTree(root->right,val);
        
        return root;
    }
};