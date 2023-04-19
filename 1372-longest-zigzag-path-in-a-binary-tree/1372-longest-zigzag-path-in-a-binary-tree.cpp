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
    int longestZigZagUtil(TreeNode* root,bool isRight,int ans)
    {
        if(root==NULL)
        {
            return ans;
        }
        
        if(isRight)
        {
            // return 1+longestZigZagUtil(root->right,!isRight);
            return max(longestZigZagUtil(root->right,!isRight,ans+1),0+longestZigZagUtil(root->right,isRight,-1));
            //current root part of zigzag || current root root of new zigzag
        }
        
        // return 1+longestZigZagUtil(root->left,!isRight);
        return max(longestZigZagUtil(root->left,!isRight,ans+1),0+longestZigZagUtil(root->left,isRight,-1));
        //current root part of zigzag || current root root of new zigzag
    }
public:
    int longestZigZag(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int ans=max(longestZigZagUtil(root,false,-1),longestZigZagUtil(root,true,-1)); //initial value of ans is -1
        
        // ans=max(ans,longestZigZag(root->left));
        // ans=max(ans,longestZigZag(root->right));
        
        return ans;
    }
};