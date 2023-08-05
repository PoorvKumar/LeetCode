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
    vector<TreeNode*> generateTreesUtil(int low,int high)
    {
        if(low==high)
        {
            TreeNode* root=new TreeNode(low);
            return vector<TreeNode*>({root});
        }
        
        vector<TreeNode*> res;
        
        for(int i=low; i<=high; i++)
        {
            vector<TreeNode*> LST;
            vector<TreeNode*> RST;
            
            if(i==low)
            {
                RST=generateTreesUtil(i+1,high);
                for(auto r:RST)
                {
                    TreeNode* root=new TreeNode(i);
                    root->right=r;
                    res.push_back(root);
                }
                continue;
            }
            
            if(i==high)
            {
                LST=generateTreesUtil(low,i-1);
                for(auto l:LST)
                {
                    TreeNode* root=new TreeNode(i);
                    root->left=l;
                    res.push_back(root);
                }
                continue;
            }
            
            LST=generateTreesUtil(low,i-1);
            RST=generateTreesUtil(i+1,high);
            
            for(auto l:LST)
            {
                for(auto r:RST)
                {
                    TreeNode* root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) 
    {
        return generateTreesUtil(1,n);
    }
};