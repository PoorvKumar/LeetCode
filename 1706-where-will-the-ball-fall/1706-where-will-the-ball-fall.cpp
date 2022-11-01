class Solution 
{
private:
    int m;
    int n;
    unordered_map<int,pair<int,int>> umap;
    
    int findBallHelper(vector<vector<int>> &grid,int i,int j)
    {
        if(i>=m) //answer
        {
            if(j<0 || j>=n) //stuck in wall
            {
                return -1;
            }
            
            return j;
        }
        
        if(j<0 || j>=n) //stuck in wall
        {
            return -1;
        }
        
        if(j<n-1 && grid[i][j]==1 && grid[i][j+1]==-1 || j>0 && grid[i][j]==-1 && grid[i][j-1]==1)
        {
            return -1; //stuck in V
        }
        
        return findBallHelper(grid,i+1,j+grid[i][j]);
    }
public:  
    vector<int> findBall(vector<vector<int>>& grid) 
    {
        vector<int> vec;
        
        m=grid.size();
        n=grid[0].size();
        
        for(int i=0; i<n; i++)
        {
            int x=findBallHelper(grid,0,i);
            vec.push_back(x);
        }
        
        return vec;
    }
};