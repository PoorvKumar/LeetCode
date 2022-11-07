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
    void addOneRowUtil(TreeNode* &root,int curdepth,int val,int depth)
    {
        if(root==NULL)
        {
            return ;
        }
        
        if(curdepth==depth)
        {
            TreeNode* p=new TreeNode(val);
            TreeNode* q=new TreeNode(val);
            
            p->left=root->left;
            p->right=NULL;
            q->right=root->right;
            q->left=NULL;
            
            root->left=p;
            root->right=q;
            
            // return root;
        }
        
        addOneRowUtil(root->left,curdepth+1,val,depth);
        addOneRowUtil(root->right,curdepth+1,val,depth);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        if(depth==1)
        {
            TreeNode* p=new TreeNode(val);
            p->left=root;
            p->right=NULL;
            
            root=p;
            return root;
        }
        
        depth=depth-2;
        
        addOneRowUtil(root,0,val,depth);
        
        return root;
    }
};