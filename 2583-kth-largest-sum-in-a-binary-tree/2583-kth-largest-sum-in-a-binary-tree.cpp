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
    vector<long long> levelSum;
    
    int findDepth(TreeNode* root,int depth,int& ans)
    {
        if(root==NULL)
        {
            return max(depth,ans);
        }
        
        ans=max(ans,findDepth(root->left,depth+1,ans));
        ans=max(ans,findDepth(root->right,depth+1,ans));
        
        return ans;
    }
    
    void kthLargestSumUtil(TreeNode* root,int depth)
    {
        if(root==NULL)
        {
            return ;
        }
        
        levelSum[depth]=levelSum[depth]+root->val;
        
        kthLargestSumUtil(root->left,depth+1);
        kthLargestSumUtil(root->right,depth+1);
    }
public:
    long long kthLargestLevelSum(TreeNode* root, int k)
    {
        int maxDepth=0;
        findDepth(root,0,maxDepth);
        
        // cout<<maxDepth<<endl;
        
        if(k>maxDepth)
        {
            return -1;
        }
        
        levelSum.assign(maxDepth,0);
        
        kthLargestSumUtil(root,0);
        
        sort(levelSum.begin(),levelSum.end(),greater<long long>());
        
        // for(auto x:levelSum)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        
        return levelSum[k-1];
    }
};