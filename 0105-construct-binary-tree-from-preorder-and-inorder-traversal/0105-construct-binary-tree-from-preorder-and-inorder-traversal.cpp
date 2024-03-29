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
    unordered_map<int,int> umap; //umap[node]=index;
    
    TreeNode* buildTreeUtil(vector<int>& preorder,vector<int>& inorder,int index,int low,int high)
    {
        if(low>high)
        {
            return NULL;
        }
        
        if(low==high && preorder[index]==inorder[low])
        {
            return new TreeNode(preorder[index]);
        }
        
        TreeNode* root=new TreeNode();
        
//         for(int i=low; i<=high; i++)
//         {
//             if(inorder[i]==preorder[index])
//             {
//                 root->val=preorder[index];
//                 root->left=buildTreeUtil(preorder,inorder,index+1,low,i-1);
//                 root->right=buildTreeUtil(preorder,inorder,index+1+i-low,i+1,high);
                
//                 return root;
//             }
//         }
        
        int i=umap[preorder[index]];
        root->val=preorder[index];
        root->left=buildTreeUtil(preorder,inorder,index+1,low,i-1);
        root->right=buildTreeUtil(preorder,inorder,index+1+i-low,i+1,high);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        for(int i=0; i<inorder.size(); i++)
        {
            umap[inorder[i]]=i;
        }
        
        return buildTreeUtil(preorder,inorder,0,0,inorder.size()-1);
    }
};