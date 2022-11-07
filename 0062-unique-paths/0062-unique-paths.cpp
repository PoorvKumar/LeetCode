class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap;
public:
    int uniquePaths(int m, int n) 
    {
        // if(m==1 && n==1)
        // {
        //     umap[m][n]=1;
        //     return umap[m][n];
        // }
        
        if(m==1 || n==1)
        {
            umap[m][n]=1;
            return umap[m][n];
        }
        
        if(umap.count(m)==1 && umap[m].count(n)==1)
        {
            return umap[m][n];
        }
        
        umap[m][n]=uniquePaths(m-1,n)+uniquePaths(m,n-1);
        return umap[m][n];
    }
};