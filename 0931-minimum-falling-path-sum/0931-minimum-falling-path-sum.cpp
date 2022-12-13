class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap;
    int n;
    
    int helper(vector<vector<int>>& matrix,int i,int j)
    {
        if(i>=n)
        {
            return 0;
        }
        
        if(j<0 || j>=n)
        {
            return INT_MAX;
        }
        
        if(umap.count(i) && umap[i].count(j))
        {
            return umap[i][j];
        }
        
        for(int k=1; k<n; k++) //going from Bottom-Up 
        {
            int minim=min(helper(matrix,i+1,k-1),helper(matrix,i+1,k));
            minim=min(minim,helper(matrix,i+1,k+1));
            
            //                  fun(i,j)
            //               /      |     \
            //              /       |      \
            //    fun(i+1,j-1) fun(i+1,j) fun(i+1,j+1)
            
            umap[i][k-1]=matrix[i][k-1]+minim;
        }
        
        return 0;
    }
    
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n=matrix.size(); 
        
//         helper(matrix,0,0);
//         int minim=INT_MAX;
        
//         for(int i=0; i<n; i++)
//         {
//             minim=minim>umap[0][i]?umap[0][i]:minim;
//         }
        
//         return minim;
        
        vector<vector<int>> dp(n+1,vector<int>(n+2,0)); //Bottom-Up DP approach -> Tabulation
        for(int i=0; i<n+1; i++)
        {
            dp[i][0]=INT_MAX;
            dp[i][n+1]=INT_MAX;
        }
        
        for(int i=0; i<n+2; i++)
        {
            dp[n][i]=0;
        }
        
        // for(auto x:dp)
        // {
        //     for(auto y:x)
        //     {
        //         cout<<y<<" "; 
        //     }
        //     cout<<endl;
        // }
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=1; j<=n; j++)
            {
                int minim=min(dp[i+1][j-1],dp[i+1][j]);
                minim=min(minim,dp[i+1][j+1]); 
                
                dp[i][j]=matrix[i][j-1]+minim;
            }
        }
        
        int res=INT_MAX;
        for(int j=1; j<=n; j++)
        {
            res=min(res,dp[0][j]);
        }
        
        return res;
    }
};