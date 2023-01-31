class Solution 
{
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) 
    {
        vector<pair<int,int>> vec;
        
        for(int i=0; i<ages.size(); i++)
        {
            vec.push_back({ages[i],scores[i]});
        }
        
        sort(vec.begin(),vec.end());
        
        // for(auto x:vec)
        // {
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        
        int ans=0;
        
        int n=ages.size();
        vector<int> dp(n,0);
        
        for(int i=0; i<n; i++)
        {
            dp[i]=vec[i].second;
            for(int j=0; j<i; j++)
            {
                if(vec[j].second<=vec[i].second)
                {
                    dp[i]=max(dp[i],dp[j]+vec[i].second);
                }
            }
            
            ans=max(ans,dp[i]);
        }
        
        return ans;
    }
};