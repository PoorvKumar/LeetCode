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
class Solution {
public:
    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        return max(1+height(root->left),1+height(root->right));
    }
    
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> v;
        v={};
        
        if(root==NULL)
        {
            return v;
        }
        
        stack<TreeNode*> stack;
        
        vector<int> vec;
        vec={};
        
        TreeNode* p;
        p=root;
        
        while(p!=NULL)
        {
            v.push_back(p->val);
            if(height(p->left)>height(p->right))
            {
                stack.push(p);
            }
            p=p->right;
        }
        
//         v.push_back(p->val);
        
//         vec=rightSideView(p->left);
//         for(int i=0; i<vec.size(); i++)
//         {
//             v.push_back(vec[i]);
//         }
    
        while(!stack.empty())
        {
            TreeNode* tmp=stack.top();
            stack.pop();
            
            vector<int> vec1=rightSideView(tmp->right); //very important logic //practise maketh genius
            
            vec=rightSideView(tmp->left);
            for(int i=vec1.size(); i<vec.size(); i++) //very important logic
            {
                v.push_back(vec[i]);
            }
        }
        
        return v;
    }
};