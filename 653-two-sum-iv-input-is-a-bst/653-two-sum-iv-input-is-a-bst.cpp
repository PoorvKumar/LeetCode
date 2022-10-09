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
    vector<int> vec;
    
    void traverse(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        
        vec.push_back(root->val);
        
        traverse(root->left);
        traverse(root->right);
    }
public:
    bool findTarget(TreeNode* root, int k) 
    {
        traverse(root);
        
        for(int i=0; i<vec.size(); i++)
        {
            int sum=k-vec[i];
            
            int x=find(vec.begin(),vec.end(),sum)-vec.begin();
            
            if(x!=i && x!=vec.size())
            {
                return true;
            }
        }
        
        return false;
    }
};