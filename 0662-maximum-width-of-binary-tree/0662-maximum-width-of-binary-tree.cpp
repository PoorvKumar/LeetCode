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
// class Solution 
// {
// private:
//     int height(TreeNode* root)
//     {
//         if(root==NULL)
//         {
//             return 0;
//         }
        
//         return 1+max(height(root->left),height(root->right));
//     }
    
//     int depth;
//     vector<vector<int>> vec;
    
//     void levelOrder(TreeNode* root,int dpt)
//     {
//         if(dpt>=depth)
//         {
//             return ;
//         }
        
//         if(root==NULL)
//         {
//             if(!vec[dpt].empty())
//             {
//                 vec[dpt].push_back(-101);
//                 levelOrder(root,dpt+1);
//                 levelOrder(root,dpt+1);
//             }
            
//             return ;
//         }
        
//         vec[dpt].push_back(root->val);
//         levelOrder(root->left,dpt+1);
//         levelOrder(root->right,dpt+1);
        
//         return ;
//     }
    
// public:
//     int widthOfBinaryTree(TreeNode* root) 
//     {
//         depth=height(root);
//         vec.assign(depth,vector<int>());
        
//         levelOrder(root,0);
        
//         int ans=0;
        
//         // for(auto x:vec)
//         // {
//         //     for(auto y:x)
//         //     {
//         //         cout<<y<<" ";
//         //     }
//         //     cout<<endl;
//         // }
        
//         for(auto x:vec)
//         {
//             int i=0;
//             int j=x.size()-1;
            
//             // while(i<j && x[i]==-101)
//             // {
//             //     i++;
//             // }
//             while(j>i && x[j]==-101)
//             {
//                 j--;
//             }
            
//             ans=max(ans,j-i+1);
//         }
        
//         return ans;
//     }
// };
class Solution {
public:
    int widthOfBinaryTree(TreeNode* a) {
        vector<int>v;
    
        if(!a)
        return 0;
        
        int ans = 1;
        queue<pair<TreeNode*,long long int>>q;
        q.push({a,0});

        while(!q.empty())
        {
            int sz = q.size();
            int a1 = 0, b1 = 0;
            int l = 0;
            int mn = q.front().second;
            for(int i = 0; i < sz; i++)
            {
                auto p = q.front();
                TreeNode* b = p.first;
                // To avoid integer overflow,
                // we modify all the address values with 
                // respect to leftmost tree address value.
                long long int k = p.second-mn;
                q.pop();
                // leftmost node
                if(i == 0)
                a1 = k;
                // rightmost node
                if(i == sz-1)
                b1 = k;

                if(b->left)
                q.push({b->left,2*k+1});
                
                if(b->right)
                q.push({b->right,2*k+2});
            }
            // To store maximum difference.
            ans = max(ans,b1-a1+1);
        }

        return ans;
        
    }
};