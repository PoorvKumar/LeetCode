class Solution 
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
        {
            return -1;
        }
        
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=1;
        
        queue<pair<int,int>> q;
        q.push({0,0}); //src {0,0}
        
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            
            int i=p.first;
            int j=p.second;
            
            vector<pair<int,int>> vec={{i-1,j-1},{i-1,j},{i-1,j+1},
                                       {i,j-1},          {i,j+1},
                                       {i+1,j-1},{i+1,j},{i+1,j+1}};
            
            for(auto x:vec)
            {
                int a=x.first;
                int b=x.second;
                
                if(a>=0 && b>=0 && a<n && b<n && grid[a][b]==0)
                {
                    if(dist[a][b]>dist[i][j]+1)
                    {
                        dist[a][b]=dist[i][j]+1;
                        q.push({a,b});
                    }
                }
            }
        }
        
        int ans=dist[n-1][n-1]!=INT_MAX?dist[n-1][n-1]:-1;
        return ans;
    }
};