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
    map<int,vector<int>> mp;
    
    bool levelOrder(TreeNode* root,int depth)
    {
        if(root==NULL)
        {
            mp[depth].push_back(-1);
            return true;
        }
        
        int k=mp[depth].size();
        if(k>0 && mp[depth][k-1]==-1)
        {
            return false; //[-1 root->val] //left filled at every level 
        }
        
        mp[depth].push_back(root->val);
        
        
        return levelOrder(root->left,depth+1) && levelOrder(root->right,depth+1);
    }
public:
    bool isCompleteTree(TreeNode* root) 
    {
        return bfs(root);
        
        if(!levelOrder(root,0)) 
        {
            return false; //some level not left filled
        }
        
        // return true;
        
        int n=mp.size();
        mp.erase(n-1);
        n--;
        // cout<<n<<endl;
        
        // for(auto x:mp)
        // {
        //     cout<<x.first<<" -> ";
        //     for(auto y:x.second)
        //     {
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        
        for(auto x:mp)
        {
            if(x.first<n-1)
            {
                for(auto y:x.second)
                {
                    if(y==-1)
                    {
                        // cout<<x.first<<endl;
                        return false; 
                    }
                }
            }
        }
        
        return true;
    }
    
private:
    bool bfs(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* p=q.front();
            q.pop();
            
            if(p==NULL)
            {
                while(!q.empty())
                {
                    p=q.front();
                    q.pop();
                    
                    if(p!=NULL)
                    {
                        return false;
                    }
                }
                
                return true;
            }
            
            q.push(p->left);
            q.push(p->right);
        }
        
        return true;
    }
};