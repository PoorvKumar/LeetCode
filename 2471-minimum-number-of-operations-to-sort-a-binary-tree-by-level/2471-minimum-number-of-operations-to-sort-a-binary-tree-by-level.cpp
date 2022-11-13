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
    void levelOrder(TreeNode* root,int depth,vector<vector<int>> &vec)
    {
        if(root==NULL)
        {
            return;
        }
        
        vec[depth].push_back(root->val);
        
        levelOrder(root->left,depth+1,vec);
        levelOrder(root->right,depth+1,vec);
    }
    
    
    int minSwaps(vector<int> &vec)
    {
        int count=0;
        int n=vec.size();
        
        vector<pair<int,int>> pos(n);
        
        for(int i=0; i<n; i++)
        {
            pos[i].first=vec[i];
            pos[i].second=i;
        }
        
        sort(pos.begin(),pos.end());
        
        vector<bool> vis(n,false);
        
        for(int i=0; i<n-1; i++)
        {
            if (vis[i] || pos[i].second==i)
            {
                continue;
            }

            int cycle_size = 0;
            int j = i;
            while (!vis[j])
            {
                vis[j] = 1;
                j = pos[j].second;
                cycle_size++;
            }
            
            if(cycle_size>0)
            {
                count=count+cycle_size-1;
            }
        }
        
        return count;
    }
    
    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        return 1+max(height(root->left),height(root->right));
    }
    
public:
    int minimumOperations(TreeNode* root) 
    {
        vector<vector<int>> vec(height(root));
        
        levelOrder(root,0,vec);
        
        int sol=0;
        
        for(int i=0; i<vec.size(); i++)
        {
            sol=sol+minSwaps(vec[i]);
        }
        
        return sol;
    }
};