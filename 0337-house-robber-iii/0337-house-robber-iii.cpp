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
    unordered_map<TreeNode*,int> umap;
    
    int robUtil(TreeNode* root)
    {
        if(root==NULL) //base case
        {
            return 0;
        }
        
        if(root->left==NULL && root->right==NULL) //base case
        {
            return root->val;
        }
        
        if(umap.count(root))
        {
            return umap[root];
        }
        
        int exclude=0+robUtil(root->left)+robUtil(root->right);
        int include=root->val;
        if(root->left!=NULL)
        {
            include=include+robUtil(root->left->left)+robUtil(root->left->right);
        }
        if(root->right!=NULL)
        {
            include=include+robUtil(root->right->left)+robUtil(root->right->right);
        }
        
        // return max(exclude,include); //Recursive Solution
        //TC: O(6^h) //as 6(2 exclude,4 include) calls for every root //where h=O(logn) as n node
        //SC: O(n)auxiliary space
        
        return umap[root]=max(exclude,include); //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n) //a sfor every root Recursion calls Memoized
        //SC: O(n) + O(n)auxiliary space
    }
public:
    int rob(TreeNode* root) 
    {
        return robUtil(root);
    }
};