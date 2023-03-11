/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
private:
    unordered_map<int,string> umap;
    
    void serializeUtil(TreeNode* root,int depth)
    {
        if(root==NULL)
        {
            umap[depth]=umap[depth]+"-1,";
            return ;
        }
        
        umap[depth]=umap[depth] + to_string(root->val) + ",";
        
        serializeUtil(root->left,depth+1);
        serializeUtil(root->right,depth+1);
    }
    
    TreeNode* removeLeaves(TreeNode* root)
    {
        if(root==NULL || root->val==-1)
        {
            return NULL;
        }
        
        root->left=removeLeaves(root->left);
        root->right=removeLeaves(root->right);
        
        return root;
    }
    
    TreeNode* deserializeUtil(vector<int>& vec,int i) //BFS
    {
        TreeNode* root=new TreeNode(-1);
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* p=q.front();
            q.pop();
            
            if(vec[i]==-1)
            {
                p=NULL;
                i++;
                continue;
            }
            
            p->val=vec[i++];
            
            p->left=new TreeNode(-1);
            p->right=new TreeNode(-1);
            
            q.push(p->left);
            q.push(p->right);
        }
        
        root=removeLeaves(root);
        
        return root;
    }
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        serializeUtil(root,0);
        
        vector<string> vec(umap.size());
        
        for(auto x:umap)
        {
            vec[x.first]=x.second;
        }
        
        string data="";
        
        for(auto x:vec)
        {
            data=data+x;
        }
        
        data.pop_back();
        // cout<<data<<endl;
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {        
        stringstream ss;
        ss<<data;
        
        // cout<<data<<endl;
        
        vector<int> vec;
        
        string x;
        // while(ss>>x)
        // {
        //     int val=stoi(x);
        //     vec.push_back(val);
        // }
        while(getline(ss,x,','))
        {
            int val=stoi(x);
            vec.push_back(val);
        }
        
        // for(auto x:vec)
        // {
        //     cout<<x<<" ";
        // }
        
        return deserializeUtil(vec,0);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;