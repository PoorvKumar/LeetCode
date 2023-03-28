class Solution 
{
private:
    int m;
    int n;
    
    int helper(vector<vector<int>>& grid)
    {
        int ans=0;
        int countTwo=0;
        int countOne=0;
        
        queue<pair<int,int>> q;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==2)
                {
                    countTwo++;
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                {
                    countOne++;
                }
            }
        }
        
        if(countTwo==0)
        {
            if(countOne!=0)
            {
                return INT_MIN;
            }
            return 0;
        }
        else if(countOne==0)
        {
            return 0;
        }
        
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            
            int i=p.first;
            int j=p.second;
            
            bool flag=false;
            
            if(i>0 && grid[i-1][j]==1)
            {
                grid[i-1][j]=2;
                flag=true;
            }
            if(i<m-1 && grid[i+1][j]==1)
            {
                grid[i+1][j]=2;
                flag=true;
            }
            if(j>0 && grid[i][j-1]==1)
            {
                grid[i][j-1]=2;
                flag=true;
            }
            if(j<n-1 && grid[i][j+1]==1)
            {
                grid[i][j+1]=2;
                flag=true;
            }
            
            if(flag)
            {
                ans++;
            }
        }
        
        if(ans==0)
        {
            return INT_MIN;
        }
        
        return 1+helper(grid);
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        m=grid.size();
        n=grid[0].size();
        
        int ans=helper(grid);
        
        return ans>=0?ans:-1;
    }
};