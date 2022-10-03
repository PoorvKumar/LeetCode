/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool search(TreeNode* root,int key) //modified search to work for Binary Tree
    {
        if(root==NULL)
        {
            return false;
        }
        
        if(key==root->val)
        {
            return true;
        }
        
        return search(root->left,key)||search(root->right,key);
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        // TreeNode* lca=root;
        
        if(root==NULL)
        {
            return NULL;
        }
        
        if(search(root->left,p->val) && search(root->right,q->val) || search(root->left,q->val) && search(root->right,p->val))
        {
            return root; //root is lca with p and q in different subtrees
        }
        
        if(root->val==p->val && search(root,q->val) || root->val==q->val && search(root,p->val))
        {
            return root; // lca==p || lca==q is true
        }
        
        TreeNode* lst=lowestCommonAncestor(root->left,p,q);
        TreeNode* rst=lowestCommonAncestor(root->right,p,q);
        
        return lst!=NULL?lst:rst;
        
        // return lowestCommonAncestor(root->left,p,q) || lowestCommonAncestor(root->right,p,q);
    }
};