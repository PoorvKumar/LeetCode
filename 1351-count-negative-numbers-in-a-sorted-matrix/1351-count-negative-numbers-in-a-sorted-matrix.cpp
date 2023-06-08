class Solution 
{
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        int ans=0;
        
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]<0)
                {
                    ans++;
                }
            }
        }
        
        return ans; 
        //TC: O(m*n)
        //SC: O(m*n)
    }
};