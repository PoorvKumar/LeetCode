/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
private:
    vector<int> res;
    unordered_set<TreeNode*> visited;
    stack<TreeNode*> path;
    
    void findPath(TreeNode* root,TreeNode* target,stack<TreeNode*>& stk)
    {
        if(root==target)
        {
            stk.push(root);
            path=stk;
            return ;
        }
        
        if(root==NULL)
        {
            return ;
        }
        
        stk.push(root);
        
        findPath(root->left,target,stk);
        findPath(root->right,target,stk);
        
        stk.pop();
        
        return ;
    }
    
    void distanceKUtil(TreeNode* root,int k,int count)
    {
        if(root==NULL || visited.count(root))
        {
            return ;
        }
        
        visited.insert(root);
        
        if(k==count)
        {
            res.push_back(root->val);
            return ;
        }
        
        distanceKUtil(root->left,k,count+1);
        distanceKUtil(root->right,k,count+1);
        
        return ;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        stack<TreeNode*> stk;
        findPath(root,target,stk);
        
        while(!path.empty())
        {
            TreeNode* p=path.top();
            path.pop();
            
            // cout<<p->val<<endl;
            
            distanceKUtil(p,k--,0);
        }
        
        return res; 
        //TC: O(n*k)
        //SC: O(n)
    }
};