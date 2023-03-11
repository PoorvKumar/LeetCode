class Solution 
{
private:
    int m;
    int n;
    
    unordered_map<int,unordered_map<int,int>> umap;
    
    int uniquePathsUtil(vector<vector<int>>& grid,int i,int j)
    {
        if(grid[i][j]==1) //base case
        {
            return 0; //obstacle
        }
        
        if(i==m-1 || j==n-1)
        {
            if(i==m-1)
            {
                for(int k=j; k<n; k++)
                {
                    if(grid[i][k]==1)
                    {
                        return 0;
                    }
                }
            }
            
            for(int k=i; k<m; k++)
            {
                if(grid[k][j]==1)
                {
                    return 0;
                }
            }
            
            return 1;
        }
        
        if(umap.count(i) && umap[i].count(j))
        {
            return umap[i][j];
        }
        
        int down=uniquePathsUtil(grid,i+1,j);
        int right=uniquePathsUtil(grid,i,j+1);
        
        // return down+right; //Recursive Solution
        //TC: O(2^(m*n)) //as 2 calls (down , right) afor each cell , m*n cells
        //SC: O(m*n) + O(m*n)auxiliary space
        
        return umap[i][j]=down+right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        
        return uniquePathsUtil(obstacleGrid,0,0);
    }
};