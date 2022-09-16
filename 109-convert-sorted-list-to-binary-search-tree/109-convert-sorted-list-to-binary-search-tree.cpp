/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        return 1+max(height(root->left),height(root->right));
    }
    
    int getBalanceFactor(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        return height(root->left)-height(root->right);
    }
    
    TreeNode* rightRotate(TreeNode* root)
    {
        TreeNode* x=root->left;
        TreeNode* tmp=x->right;
        
        x->right=root;
        root->left=tmp;
        
        return x;
    }
    
    TreeNode* leftRotate(TreeNode* root)
    {
        TreeNode* x=root->right;
        TreeNode* tmp=x->left;
        
        x->left=root;
        root->right=tmp;
        
        return x;
    }
    
    TreeNode* insert(TreeNode* root,int val)
    {
        if(root==NULL)
        {
            root=new TreeNode(0);
            root->val=val;
            root->left=NULL;
            root->right=NULL;
            
            return root;
        }
        
        if(val<root->val)
        {
            root->left=insert(root->left,val);
        }
        else if(val>root->val)
        {
            root->right=insert(root->right,val);
        }
        else
        {
            return root;
        }
        
        int balancefactor=getBalanceFactor(root);
        
        if(balancefactor>1 && val<root->left->val)
        {
            return rightRotate(root);
        }
        
        if(balancefactor<-1 && val>root->right->val)
        {
            return leftRotate(root);
        }
        
        if(balancefactor>1 && val>root->left->val)
        {
            root->left=leftRotate(root->left);
            return rightRotate(root);
        }
        
        if(balancefactor<-1 && val<root->right->val)
        {
            root->right=rightRotate(root->right);
            return leftRotate(root);
        }
        
        return root;
    }
    
public:
    
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(head==NULL)
        {
            return NULL;
        }
        
        TreeNode* root;
        root=NULL;
        
        while(head!=NULL)
        {
            root=insert(root,head->val);
            head=head->next;
        }
        
        return root;
    }
};