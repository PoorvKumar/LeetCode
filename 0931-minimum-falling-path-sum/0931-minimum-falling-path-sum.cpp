class Solution 
{
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n=matrix.size(); 
        
//         dpTopDown.assign(n,vector<int>(n,-1));
        
//         helper(matrix,n-1,0);
//         int minim=INT_MAX;
        
//         for(auto x:dpTopDown)
//         {
//             for(auto y:x)
//             {
//                 cout<<y<<" ";
//             }
//             cout<<endl;
//         }
        
//         for(int i=0; i<n; i++)
//         {
//             minim=min(minim,dpTopDown[0][i]);
//         }
        
//         return minim;
        
//         vector<vector<int>> dp(n+1,vector<int>(n+2,0)); //Bottom-Up DP approach -> Tabulation
//         for(int i=0; i<n+1; i++)
//         {
//             dp[i][0]=INT_MAX;
//             dp[i][n+1]=INT_MAX;
//         }
        
//         for(int i=0; i<n+2; i++)
//         {
//             dp[n][i]=0;
//         }
        
//         // for(auto x:dp)
//         // {
//         //     for(auto y:x)
//         //     {
//         //         cout<<y<<" "; 
//         //     }
//         //     cout<<endl;
//         // }
        
//         for(int i=n-1; i>=0; i--)
//         {
//             for(int j=1; j<=n; j++)
//             {
//                 int minim=min(dp[i+1][j-1],dp[i+1][j]);
//                 minim=min(minim,dp[i+1][j+1]); 
                
//                 dp[i][j]=matrix[i][j-1]+minim;
//             }
//         }
        
//         int res=INT_MAX;
//         for(int j=1; j<=n; j++)
//         {
//             res=min(res,dp[0][j]);
//         }
        
//         return res;
        
        for(int i=n-2; i>=0; i--)
        {
            for(int j=0; j<n; j++)
            {
                if(j==0 || j==n-1)
                {
                    if(j==0)
                    {
                        matrix[i][j]=matrix[i][j]+min(matrix[i+1][j],matrix[i+1][j+1]);
                    }
                    else
                    {
                        matrix[i][j]=matrix[i][j]+min(matrix[i+1][j-1],matrix[i+1][j]);
                    }
                }
                else
                {
                    int minim=min(matrix[i+1][j-1],matrix[i+1][j]);
                    minim=min(minim,matrix[i+1][j+1]);
                    matrix[i][j]+=minim;
                }
            }
        }
        
        int res=matrix[0][0];
        for(int i=0; i<n; i++)
        {
            res=min(res,matrix[0][i]);
        }
        
        return res;
    }
};