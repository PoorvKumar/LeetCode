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
class Solution {
private:
    TreeNode* minVal(TreeNode* root)
    {
        if(root==NULL)
        {
            return root;
        }
        if(root->left!=NULL)
        {
            return minVal(root->left);
        }
        
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root==NULL)
        {
            return NULL;
        }
        
        if(key<root->val)
        {
            root->left=deleteNode(root->left,key);
        }
        else if(key>root->val)
        {
            root->right=deleteNode(root->right,key);
        }
        else
        {
            if(root->left==NULL && root->right==NULL)
            {
                return NULL;
            }
            else if(root->left==NULL || root->right==NULL)
            {
                TreeNode* tmp;
                if(root->left==NULL)
                {
                    tmp=root->right;
                }
                else
                {
                    tmp=root->left;
                }
                // delete root;
                return tmp;
            }
            else
            {
                TreeNode* tmp=minVal(root->right);
                root->right=deleteNode(root->right,tmp->val);
                root->val=tmp->val;
                return root;
            }
        }
        
        return root;
    }
};