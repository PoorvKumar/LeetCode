class Solution 
{
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) 
    {
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(auto &x:roads)
        {
            int i=x[0];
            int j=x[1];

            dp[i][j]++;
            dp[j][i]++;
        }

        vector<int> vec(n,0);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                vec[i]=vec[i]+dp[i][j];
            }
        }

        int ans=0;

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int val=vec[i]+vec[j]-(dp[i][j]!=0?1:0);
                ans=max(ans,val);
            }
        }

        return ans;
    }
};