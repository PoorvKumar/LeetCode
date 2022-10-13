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
    vector<vector<int>> vec;
    
    vector<int> pathSumUtil(TreeNode* root,int targetSum,vector<int> v)
    {
        if(root==NULL)
        {
            return vector<int>(); //return empty vector,i.e, an object of type class vector which is empty
        }                         //by calling Non-Parameterised Constructor of class vector
        
        if(root->left==NULL && root->right==NULL)
        {
            if(root->val==targetSum)
            {
                v.push_back(root->val);
                vec.push_back(v);
                return v;
            }
            else
            {
                v.clear();
                return v;
            }
        }
        
        v.push_back(root->val);
        
         //instead of pushing here we push_back(v) in line 29 ,so that even when 1 root node in tree then it can return vector<vector<int>> else return v; in line 28 executes and function call ends there
        
        // vec.push_back(pathSumUtil(root->left,targetSum-root->val,v));
        // vec.push_back(pathSumUtil(root->right,targetSum-root->val,v));
        
        pathSumUtil(root->left,targetSum-root->val,v);
        pathSumUtil(root->right,targetSum-root->val,v);
        
        // v.clear(); //all the paths from root to node before leaf which might be possible answer but is not
        return v; //try commneting above to see what happens
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> v;
        pathSumUtil(root,targetSum,v);
        
        vector<vector<int>> pathSum;
        
        for(int i=0; i<vec.size(); i++)
        {
            if(!vec[i].empty())
            {
                pathSum.push_back(vec[i]);
            }
        }
        
        vec.clear();
        
        return pathSum;
    }
};  

