class Solution 
{
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<bool>> marked(m,vector<bool>(n,false));
        
        queue<pair<int,int>> q;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==0)
                {
                    marked[i][j]=true;
                }
                else if(i==0 || i==m-1 || j==0 || j==n-1)
                {
                    q.push({i,j});
                    marked[i][j]=true;
                }
            }
        }
        
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            
            int i=p.first;
            int j=p.second;
            
            //up
            if(i>0 && !marked[i-1][j])
            {
                q.push({i-1,j});
                marked[i-1][j]=true;
            }
            
            //down
            if(i<m-1 && !marked[i+1][j])
            {
                q.push({i+1,j});
                marked[i+1][j]=true;
            }
            
            //left
            if(j>0 && !marked[i][j-1])
            {
                q.push({i,j-1});
                marked[i][j-1]=true;
            }
            
            //right
            if(j<n-1 && !marked[i][j+1])
            {
                q.push({i,j+1});
                marked[i][j+1]=true;
            }
        }
        
        int ans=0;
        
        // for(int i=0; i<m; i++)
        // {
        //     for(int j=0; j<n; j++)
        //     {
        //         if(!marked[i][j])
        //         {
        //             ans++;
        //         }
        //     }
        // }
        
        for(auto x:marked)
        {
            for(auto y:x)
            {
                if(!y)
                {
                    ans++;
                }
            }
        }
        
        return ans; //BFS Solution
        //TC: O(m*n)+O(m+n)
        //SC: O(m*n)+O(m+n)
    }
};