class Solution 
{
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        
        int ans=0;
        int j=0;
        
        for(int i=n-1; i>=0; i--)
        {
            while(j<m && grid[j][i]>=0)
            {
                j++;
            }
            
            ans=ans+m-j;
        }
        
        return ans;
    }
};