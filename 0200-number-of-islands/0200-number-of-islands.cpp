class Solution 
{
private:
    vector<vector<bool>> visited;
    
    void bfs(vector<vector<char>>& grid,int i,int j)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        queue<pair<int,int>> q;
        q.push({i,j});
        
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            
            int x=p.first;
            int y=p.second;
            
            if(x<0 || x>m-1 || y<0 || y>n-1)
            {
                continue;
            }
            
            if(grid[x][y]!='1' || visited[x][y])
            {
                continue;
            }
            
            visited[x][y]=true;
            
            q.push({x-1,y});
            q.push({x+1,y});
            q.push({x,y-1});
            q.push({x,y+1});
        }
        
        return ;
    }
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        
        visited.assign(m,vector<bool>(n,false));
        
        int ans=0;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]=='1' && !visited[i][j])
                {
                    ans++;
                    bfs(grid,i,j); //O(mn)
                }
            }
        }
        
        return ans; //O(m*m*n*n)
    }
};