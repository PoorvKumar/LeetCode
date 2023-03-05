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
        vector<long long> vec;
        
        kthLargestLevelSumUtil(root,0);
        // cout<<umap.size()<<endl;
        
        if(k>umap.size())
        {
            return -1;
        }
        
        for(auto x:umap)
        {
            // cout<<x.first<<" -> "<<x.second<<endl;
            vec.push_back(x.second);
        }
        
        sort(vec.begin(),vec.end(),greater<long long>());
        
        return vec[k-1];
    }
};