class Solution 
{
private:
    vector<vector<bool>> visited;
    
    void bfs(vector<vector<char>>& grid,int i,int j)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        visited[i][j]=true;
        
        queue<pair<int,int>> q;
        q.push({i,j});
        
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            
            int x=p.first;
            int y=p.second;
            
            //up
            if(x>0 && grid[x-1][y]=='1' && !visited[x-1][y])
            {
                q.push({x-1,y});
                visited[x-1][y]=true;
            }
            
            //down
            if(x<m-1 && grid[x+1][y]=='1' && !visited[x+1][y])
            {
                q.push({x+1,y});
                visited[x+1][y]=true;
            }
            
            //left
            if(y>0 && grid[x][y-1]=='1' && !visited[x][y-1])
            {
                q.push({x,y-1});
                visited[x][y-1]=true;
            }
            
            //right
            if(y<n-1 && grid[x][y+1]=='1' && !visited[x][y+1])
            {
                q.push({x,y+1});
                visited[x][y+1]=true;
            }
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
                    bfs(grid,i,j);
                }
            }
        }
        
        return ans;
    }
};