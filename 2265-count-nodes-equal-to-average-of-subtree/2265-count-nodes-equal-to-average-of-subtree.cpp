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
    int count=0;
    
    vector<int> averageOfSubtreeUtil(TreeNode* root)
    {
        if(root==NULL)
        {
            return vector<int>(2,0);
        }
        
        vector<int> lst=averageOfSubtreeUtil(root->left);
        vector<int> rst=averageOfSubtreeUtil(root->right);
        
        int sum=root->val+lst[0]+rst[0];
        int n=lst[1]+rst[1]+1;
        
        if(root->val==sum/n)
        {
            count++;
        }
        
        return vector<int>({sum,n});
    }
public:
    int averageOfSubtree(TreeNode* root) 
    {
        vector<int> res=averageOfSubtreeUtil(root);
        
        return count;
    }
};