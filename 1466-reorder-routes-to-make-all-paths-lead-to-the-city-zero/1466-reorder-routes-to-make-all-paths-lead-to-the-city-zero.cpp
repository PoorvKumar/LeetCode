class Solution 
{
private:
    vector<vector<int>> adjList;
    unordered_map<int,unordered_map<int,int>> umap;
    vector<bool> visited;
    
    int dfs(int src)
    {
        if(visited[src])
        {
            return 0;
        }
        
        visited[src]=true;
        int ans=0;
        
        for(auto node:adjList[src])
        {
            if(!visited[node])
            {
                if(umap.count(src) && umap[src].count(node))
                {
                    ans++;
                }
                ans=ans+dfs(node);
            }
        }
        
        for(auto x:umap)
        {
            if(x.second.count(src))
            {
                ans=ans+dfs(x.first);
            }
        }
        
        // for(int i=0; i<visited.size(); i++)
        // {
        //     if(!visited[i])
        //     {
        //         ans=ans+dfs(i);
        //     }
        // }
        
        return ans;
    }
    
    int bfs(int src)
    {
        queue<int> q;
        q.push(src);
        visited[src]=true;
        
        int ans=0;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto neighbour:adjList[node])
            {
                if(!visited[neighbour])
                {
                    if(umap.count(node) && umap[node].count(neighbour))
                    {
                        ans++;
                    }
                    visited[neighbour]=true;
                    q.push(neighbour);
                }
            }
        }
        
        return ans;
    }
    
public:
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        adjList.assign(n,vector<int>());
        visited.assign(n,false);
        
        for(auto edge:connections)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
            umap[edge[0]][edge[1]]=1;
        }
        
        // for(auto x:umap)
        // {
        //     cout<<x.first<<" -> ";
        //     for(auto y:x.second)
        //     {
        //         cout<<y.first<<" ";
        //     }
        //     cout<<endl;
        // }
        
        // return dfs(0);
        return bfs(0);
    }
};