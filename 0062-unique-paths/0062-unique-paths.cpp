class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap;
public:
    int uniquePaths(int m, int n) 
    {        
//         //top-down DP approach-> Recursion + Memomization
//         if(m==1 || n==1)  
//         {
//             umap[m][n]=1;
//             return umap[m][n];
//         }
        
//         if(umap.count(m)==1 && umap[m].count(n)==1)
//         {
//             return umap[m][n];
//         }
        
//         umap[m][n]=uniquePaths(m-1,n)+uniquePaths(m,n-1);
//         return umap[m][n];
        
        // bottom-up DP approach-> Tabulation
        if(m==1 || n==1)
        {
            return 1;
        }
        
        vector<vector<int>> tab(m+1,vector<int>(n+1));
        
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(i==1 || j==1)
                {
                    tab[i][j]=1;
                }
            }
        }
        
        for(int i=2; i<=m; i++)
        {
            for(int j=2; j<=n; j++)
            {
                tab[i][j]=tab[i-1][j]+tab[i][j-1];
            }
        }
        
        return tab[m][n]+2;
    }
};