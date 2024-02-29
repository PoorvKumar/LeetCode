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
    vector<int> last;
    
    bool isEvenOddTreeUtil(TreeNode* root,int level)
    {
        if(root==NULL)
        {
            return true;
        }
        
        if(level%2) //odd level -> strictly decreasing even
        {
            if(root->val%2!=0 || root->val>=last[level])
            {
                return false;
            }
        }
        else //even level -> strictly increasing odd
        {
            if(root->val%2!=1 || root->val<=last[level])
            {
                return false;
            }
        }
        
        last[level]=root->val;
        
        return isEvenOddTreeUtil(root->left,level+1) && isEvenOddTreeUtil(root->right,level+1);
    }
public:
    bool isEvenOddTree(TreeNode* root) 
    {
        last.assign(1e6+1,-1);
        
        for(int i=1; i<=1e6; i=i+2) //O(1)
        {
            last[i]=INT_MAX;
        }
        
        return isEvenOddTreeUtil(root,0);
    }
};

// approach -> find the level order traversal and then check the condition
// approach -> remember the last value of the levels, and compare with current and update the last