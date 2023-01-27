class Solution 
{
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        unordered_map<int,int> umap;
        for(int i=0; i<nums.size(); i++)
        {
            umap[nums[i]]++;
        }
        
        if(umap.size()==1)
        {
            return nums[0]*umap[nums[0]];
        }
        
        int n=umap.size();
        
        vector<int> vec;
        for(auto x:umap)
        {
            vec.push_back(x.first);
        }
        
        sort(vec.begin(),vec.end());
        int maxim=0;
        
        vector<int> dp(n,0);
        dp[0]=vec[0]*umap[vec[0]];
        
        int i=1;
        
        if(vec[1]==vec[0]+1)
        {
            dp[1]=vec[1]*umap[vec[1]];
            i++;
        }
        
        maxim=max(dp[0],dp[1]);
        
        for( ; i<n; i++)
        {
            int x=vec[i]*umap[vec[i]];
            if(vec[i]!=vec[i-1]+1)
            {
                int maxLast=0;
                for(int j=0; j<=i-1; j++) //maximum value till i-1
                {
                    maxLast=max(maxLast,dp[j]);
                }
                dp[i]=maxLast+x;
                // dp[i]=dp[i-1]+x;
            }
            else
            {
                int maxLast=0;
                for(int j=0; j<i-1; j++) //maximum value till i-2 
                {
                    maxLast=max(maxLast,dp[j]);
                }
                dp[i]=maxLast+x;
                // dp[i]=dp[i-2]+x;
            }
            maxim=max(maxim,dp[i]);
        }
        
        return maxim;
        // return max(dp[n-1],dp[n-2]);
    }
};