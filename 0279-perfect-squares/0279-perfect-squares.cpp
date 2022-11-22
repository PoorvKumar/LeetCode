class Solution 
{
private:
    unordered_map<int,int> umap;
    
    int numSquareUtil(vector<int>& vec,int n)
    {
        if(n==0) //Base Case
        {
            return 0;
        }
        
        if(n<0) //Base Case
        {
            return INT_MAX;
        }
        
        int res=INT_MAX;
        
        for(int i=0; i<vec.size(); i++) //Top-Down DP approach -> Recursion + Memoization
        {
            int x=umap.count(n-vec[i])?umap[n-vec[i]]:numSquareUtil(vec,n-vec[i]);
            if(x!=INT_MAX && x+1<res)
            {
                res=x+1;
            }
        }
        
        return umap[n]=res;
    }
    
public:
    int numSquares(int n) 
    {
        vector<int> vec;
        int i=1;
        
        while(i*i<=n)
        {
            vec.push_back(i*i);
            i++;
        }
        
        // for(auto x:vec)
        // {
        //     cout<<x<<" ";
        // }
        
        return numSquareUtil(vec,n); //Top-Down DP approach -> Recursion + Memoization
        
//         // Bottom-Up DP approach -> Tabulation
//         vector<vector<int>> dp;
//         vector<vector<int>> dp(n+1,vector<int>(vec.size()+1,INT_MAX));
        
//         dp[0].assign(vec.size()+1,0);
        
//         for(int i=1; i<=n; i++)
//         {
//             for(int j=0; j<vec.size(); j++)
//             {
//                 dp[i][j]=min(dp[i][j],dp[i][j-vec[i]])+1;
//             }
//         }
        
        
    }
};

