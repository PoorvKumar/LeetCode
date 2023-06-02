class Solution 
{
private:
    // unordered_map<pair<int,int>,vector<pair<int,int>>> umap; //umap[{srci,srcj}]
    // unordered_map<int,unordered_map<int,vector<pair<int,int>>>> umap;
    
    unordered_map<int,vector<int>> umap; //umap[src] //nodes as index instead of points
    
    bool detonate(vector<int>& x,vector<int>& y)
    {
        double dist=pow(y[0]-x[0],2)+pow(y[1]-x[1],2);
        dist=sqrt(dist);
        
        return x[2]>=dist;
    }
    
    // unordered_set<pair<int,int>> visited;
    // unordered_map<int,unordered_set<int>> visited;
    vector<bool> visited;
    
    int dfs(int i,vector<vector<int>>& bombs)
    {
        // visited[i].insert(j);
        visited[i]=true;
        int ans=1;
        
        for(auto x:umap[i])
        {
            if(!visited[x])
            {
                ans=ans+dfs(x,bombs);
            }
        }
        
        return ans;
    }
    
public:
    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        visited.assign(bombs.size(),false);
        
        for(int i=0; i<bombs.size(); i++)
        {
            for(int j=0; j<bombs.size(); j++)
            {
                bool willDetonate=detonate(bombs[i],bombs[j]);
                if(willDetonate)
                {
                    // pair<int,int> p={bombs[i][0],bombs[i][1]};
                    // pair<int,int> q={bombs[j][0],bombs[j][1]};

                    // umap[p.first][p.second].push_back(q);
                    
                    umap[i].push_back(j);
                }
            }
        }
        
        int ans=0;
        for(auto x:umap)
        {
            visited.assign(bombs.size(),false);
            int val=dfs(x.first,bombs);
            ans=max(ans,val);
        }
        
        return ans;
    }
};