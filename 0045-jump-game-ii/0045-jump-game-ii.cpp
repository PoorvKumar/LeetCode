class Solution 
{
private:
    unordered_map<int,int> umap;
    
    int jumpHelper(vector<int>& nums,int index) //Top-Down DP approach -> Recursion + Memoization
    {
        if(index>=nums.size()-1)
        {
            umap[nums.size()-1]=0;
            return 0;
        }
        
        int minim=INT_MAX;
        
        for(int i=1; i<=nums[index]; i++)
        {
            if(!umap.count(index+i))
            {
                umap[index+i]=jumpHelper(nums,index+i);
            }
            
            minim=min(minim,umap[index+i]);
        }
        
        umap[index]=minim<INT_MAX?1+minim:minim;
        
        return umap[index];
    }
public:
    int jump(vector<int>& nums) 
    {
        // return jumpHelper(nums,0); //Top-Down DP approach -> Recursion + Memoization
        
        //Bottom-Up DP approach -> Tabulation
        
        vector<int> dp(nums.size(),INT_MAX);
        dp[nums.size()-1]=0;
        
        for(int i=nums.size()-2; i>=0; i--)
        {
            int x=INT_MAX;
            for(int j=1; j<=nums[i]; j++)
            {
                if(i+j>=nums.size()-1)
                {
                    dp[i]=1;
                    break;
                }
                else
                {
                    x=min(x,dp[i+j]);
                    // cout<<x<<" "<<i<<endl;
                    if(x!=INT_MAX)
                    {
                        dp[i]=1+x;
                    }
                }
            }
        }
        
        // for(auto x:dp)
        // {
        //     cout<<x<<" ";
        // }
        
        return dp[0];
    }
};