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
    vector<vector<int>> levelOrder;
    int n=0; //in-class initializer
    
    void levelOrderUtil(TreeNode* root,int depth)
    {
        if(root==NULL)
        {
            return ;
        }
        
        levelOrder[depth].push_back(root->val);
        
        n=max(n,depth+1);
        
        levelOrderUtil(root->left,depth+1);
        levelOrderUtil(root->right,depth+1);
        
        return ;
    }
public:
    // Solution()
    // {
    //     levelOrder.assign(2000,vector<int>());
    //     // n=0;
    // }
    
    Solution(): levelOrder(vector<vector<int>>(2000,vector<int>())),n(0){}; //delegation of constructor
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        // levelOrder.assign(2000,vector<int>());
        
        levelOrderUtil(root,0);
        
        vector<vector<int>> res;
        
        for(int i=0; i<n; i++)
        {
            if(i%2!=0)
            {
                reverse(levelOrder[i].begin(),levelOrder[i].end());
            }
            
            res.push_back(levelOrder[i]);
        }
        
        return res;
    }
};