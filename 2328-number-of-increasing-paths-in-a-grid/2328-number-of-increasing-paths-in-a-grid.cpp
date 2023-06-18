class Solution 
{
private:
    unsigned long long M=1e9+7;
    
    int m;
    int n;
    vector<unordered_set<int>> visited;
    
    unordered_map<int,unordered_map<int,int>> umap; //umap[i][j]
    
    int countPathsUtil(vector<vector<int>>& grid,int i,int j,unordered_set<int>& path)
    {
        int cell=grid[i][j];
        path.insert(cell);
        
        if(umap.count(i) && umap[i].count(j))
        {
            return umap[i][j];
        }
        
        // int ans;
//         bool flag=false;
        
//         for(auto &x:visited)
//         {
//             if(x==path)
//             {
//                 ans=0;
//                 flag=true;
//                 break;
//             }
//         }
        
//         if(!flag)
//         {
//             ans=1;
//             if(path.size()>1)
//             {
//                 visited.push_back(path);
//             }
//         }
        
        int ans=1;
        
        //up
        if(i>0 && grid[i-1][j]>cell)
        {
            int val=countPathsUtil(grid,i-1,j,path)%M;
            ans=ans%M+val%M;
        }
        
        //down
        if(i<m-1 && grid[i+1][j]>cell)
        {
            int val=countPathsUtil(grid,i+1,j,path)%M;
            ans=ans%M+val%M;
        }
        
        //left
        if(j>0 && grid[i][j-1]>cell)
        {
            int val=countPathsUtil(grid,i,j-1,path)%M;
            ans=ans%M+val%M;
        }
        
        //right
        if(j<n-1 && grid[i][j+1]>cell)
        {
            int val=countPathsUtil(grid,i,j+1,path)%M;
            ans=ans%M+val%M;
        }
        
        path.erase(cell);
        
        // return ans%M;
        
        return umap[i][j]=ans%M;
    }
    
public:
    int countPaths(vector<vector<int>>& grid) 
    {
        m=grid.size();
        n=grid[0].size();
        
        int ans=0;
        unordered_set<int> path;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                // path.clear();
                int val=countPathsUtil(grid,i,j,path);
                ans=ans%M+val%M;
                ans=ans%M;
            }
        }
        
        return ans%M;
    }
};