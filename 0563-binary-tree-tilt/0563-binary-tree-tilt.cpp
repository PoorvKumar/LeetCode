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
    int sumNodes(TreeNode* root,int &sum)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        sum=sum+root->val;
        
        sumNodes(root->left,sum);
        sumNodes(root->right,sum);
        
        return sum;
    }
    
    int findTiltUtil(TreeNode* root,int &sum)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int lsum=0;
        int rsum=0;
        
        root->val=abs(sumNodes(root->left,lsum)-sumNodes(root->right,rsum));
        sum=sum+root->val;
                
        findTiltUtil(root->left,sum);
        findTiltUtil(root->right,sum);
        
        return sum;
    }
public:
    int findTilt(TreeNode* root) 
    {
        int sum=0;
        return findTiltUtil(root,sum);
    }
};