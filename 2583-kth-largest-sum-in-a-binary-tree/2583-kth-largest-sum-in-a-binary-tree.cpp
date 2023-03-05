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
    unordered_map<int,long long> umap;
    
    void kthLargestLevelSumUtil(TreeNode* root,int depth)
    {
        if(root==NULL)
        {
            return ;
        }
        
        umap[depth]=umap[depth]+root->val;
        
        kthLargestLevelSumUtil(root->left,depth+1);
        kthLargestLevelSumUtil(root->right,depth+1);
        
        return;
    }
public:
    long long kthLargestLevelSum(TreeNode* root, int k)
    {
        priority_queue<long long> pq; //max heap
        
        kthLargestLevelSumUtil(root,0);
        
        if(k>umap.size())
        {
            return -1;
        }
        
        for(auto x:umap)
        {
            pq.push(x.second);
        }
        
        k--;
        
        while(k--)
        {
            pq.pop();
        }
        
        return pq.top();
    }
};