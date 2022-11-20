class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap;
public:
//     int minimumTotal(vector<vector<int>>& triangle,int i=0,int j=0) 
//     {
//         if(i>=triangle.size())  //Top-Down DP approach-> Recursion + Memoizatioon
//         {
//             return 0;    
//         }
        
//         if(umap.count(i)==1 && umap[i].count(j))
//         {
//             return umap[i][j];
//         }
        
//         umap[i][j]=triangle[i][j]+min(minimumTotal(triangle,i+1,j),minimumTotal(triangle,i+1,j+1));
//         return umap[i][j];
//     }
    
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size()));
        
        int n=triangle.size();
        
        for(int i=0; i<triangle[n-1].size(); i++)
        {
            dp[n-1][i]=triangle[n-1][i];
        }
        
        for(int i=n-2; i>=0; i--)
        {
            for(int j=0; j<triangle[i].size(); j++)
            {
                dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
            }
        }
        
        return dp[0][0];
    }
};