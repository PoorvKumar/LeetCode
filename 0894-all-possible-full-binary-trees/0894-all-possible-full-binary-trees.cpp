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
    unordered_map<int,vector<TreeNode*>> umap;
    
    vector<TreeNode*> allPossibleFBTUtil(int n)
    {
        if(n%2==0)
        {
            return vector<TreeNode*>();
        }
        
        if(n==1)
        {
            TreeNode* root=new TreeNode(0);
            return vector<TreeNode*>({root});
        }
        
        if(umap.count(n))
        {
            return umap[n];
        }
        
        vector<TreeNode*> res;
        
        for(int i=1; i<=n-1; i=i+2)
        {
            vector<TreeNode*> LST=allPossibleFBTUtil(i);
            vector<TreeNode*> RST=allPossibleFBTUtil(n-1-i);
            
            // TreeNode* root=new TreeNode(0); //causes WA
            
            for(auto l:LST)
            {
                for(auto r:RST)
                {
                    TreeNode* root=new TreeNode(0);
                    
                    root->left=l;
                    root->right=r;
                    
                    res.push_back(root);
                }
            }
        }
        
        // return res; //Recursive Solution
        //TC: O(n*2^(n/2)) //as 2 Recursion calls for all nodes divided between LST,RST //and O(n) for all splits
        //SC: O(n*2^(n/2)) //for all splits object of type class vector<TreeNode*>
        
        return umap[n]=res; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(2^(n/2)) //as for every split 2 (LST,RST) Recursion calls Memoized
        //SC: O(n*2^(n/2))
    }
public:
    vector<TreeNode*> allPossibleFBT(int n) 
    {
        return allPossibleFBTUtil(n);
    }
};