class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap;
    int m;
    int n;
    
    int minPathSumUtil(vector<vector<int>> &grid,int i,int j)
    {
        if(umap.count(i)==1 && umap[i].count(j)==1)
        {
            return umap[i][j];
        }
        
        if(i==m-1 && j==n-1)
        {
            umap[i][j]=grid[i][j];
            return umap[i][j];
        }
        
        if(i==m-1 || j==n-1)
        {
            if(i==m-1)
            {
                umap[i][j]=grid[i][j]+minPathSumUtil(grid,i,j+1);
                return umap[i][j];
            }
            umap[i][j]=grid[i][j]+minPathSumUtil(grid,i+1,j);
            return umap[i][j];
        }
        
        int x=grid[i][j]+minPathSumUtil(grid,i+1,j);
        int y=grid[i][j]+minPathSumUtil(grid,i,j+1);
        
        umap[i][j]=min(x,y);
        return umap[i][j];
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        m=grid.size();
        n=grid[0].size();
        
        return minPathSumUtil(grid,0,0);
    }
};