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
    void binaryTreePathsHelper(TreeNode* root,string s,vector<string> &vec)
    {
        if(root==NULL)
        {
            return;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            s=s+to_string(root->val);
            vec.push_back(s);
        }
        
        s=s+to_string(root->val)+"->";
        
        binaryTreePathsHelper(root->left,s,vec);
        binaryTreePathsHelper(root->right,s,vec);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        string s="";
        vector<string> vec;
        
        binaryTreePathsHelper(root,s,vec);
        
        return vec;
    }
};