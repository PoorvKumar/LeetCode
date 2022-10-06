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
    int getMax(TreeNode* root)
    {
        int m=-10001;
        
        TreeNode* p=root;
        
        while(p!=NULL)
        {
            m=p->val;
            p=p->right;
        }
        
        return m;
    }
    
    int getMin(TreeNode* root)
    {
        int m=-10001;
        
        TreeNode* p=root;
        
        while(p!=NULL)
        {
            m=p->val;
            p=p->left;
        }
        
        return m;
    }
    
public:
    int getMinimumDifference(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 10001;
        }
        
        int mL=abs(root->val-getMax(root->left));
        int mR=abs(root->val-getMin(root->right));
        
        mL=min(mL,mR);
        
        int LST=getMinimumDifference(root->left);
        int RST=getMinimumDifference(root->right);
        
        LST=min(LST,RST);
        
        return min(mL,LST);
    }
};