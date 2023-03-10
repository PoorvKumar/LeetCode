class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap;
    
    int uniquePathsUtil(int i,int j,int m,int n)
    {
        if(i==m-1 || j==n-1)
        {
            return 1;
        }
        
        if(umap.count(i) && umap[i].count(j))
        {
            return umap[i][j];
        }
        
        // int down=uniquePathsUtil(i+1,j,m,n);
        // int right=uniquePathsUtil(i,j+1,m,n);
        
        //down
        umap[i+1][j]=uniquePathsUtil(i+1,j,m,n);
        //right
        umap[i][j+1]=uniquePathsUtil(i,j+1,m,n);
        
        // return down+right; //Recursive Solution
        //TC: O(2^(m*n)) //as 2 calls at every cell && m*n cells
        //SC: O(m*n)
        
        return umap[i][j]=umap[i+1][j] + umap[i][j+1]; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(m*n) //as recursive calls for all cells but memoized the solution for all cells so call once for each cell
        //SC: O(m*n)
    }
public:
    int uniquePaths(int m, int n) 
    {
        return uniquePathsUtil(0,0,m,n);
    }
};