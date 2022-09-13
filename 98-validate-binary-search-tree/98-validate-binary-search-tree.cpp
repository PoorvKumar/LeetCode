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
public:
    vector<int> inordertraversal(TreeNode* root)
    {
        vector<int> v={};
        vector<int> vec={};
        
        if(root==NULL)
        {
            return v;
        }
        
        if(root->left!=NULL)
        {
            vec=inordertraversal(root->left);
            for(int i=0; i<vec.size(); i++)
            {
                v.push_back(vec[i]);
            }
        }
        
        v.push_back(root->val);
        
        if(root->right!=NULL)
        {
            vec=inordertraversal(root->right);
            for(int i=0; i<vec.size(); i++)
            {
                v.push_back(vec[i]);
            }
        }
        
        return v;
    }
    
    bool isValidBST(TreeNode* root) 
    {
        if(root==NULL)
        {
            return true;
        }
        
        vector<int> vl=inordertraversal(root->left);
        sort(vl.rbegin(),vl.rend());
        
        vector<int> vr=inordertraversal(root->right);
        
        if(vl.empty() && vr.empty())
        {
            return true;
        }
        
        if(vl.empty())
        {
            return root->val<vr[0] && isValidBST(root->right);
        }
        
        if(vr.empty())
        {
            return root->val>vl[0] && isValidBST(root->left);
        }
        
        if(vl[0]<root->val && root->val<vr[0])
        {
            return isValidBST(root->left) && isValidBST(root->right);
        }
        else
        {
            return false;
        }
    }
};