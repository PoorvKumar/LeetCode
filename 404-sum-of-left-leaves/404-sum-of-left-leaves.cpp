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
    int sumOfLeftLeaves(TreeNode* root) 
    {
        int sum=0;
        
        if(root==NULL)
        {
            return sum;
        }
        
        stack<TreeNode*> s;
        while(root!=NULL)
        {
            if(root->left!=NULL)
            {
                s.push(root->left);
            }
            
            root=root->right;
        }
        
        while(!s.empty())
        {
            TreeNode* p;
            p=s.top();
            s.pop();
            
            if(p->left==NULL && p->right==NULL)
            {
                sum=sum+p->val;
            }
            
            sum=sum+sumOfLeftLeaves(p);
        }
        
        return sum;
    }
};