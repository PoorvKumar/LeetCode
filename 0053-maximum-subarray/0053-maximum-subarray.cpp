class Solution 
{
private:
    // unordered_map<int,unordered_map<bool,int>> umap; //umap[index][pick]
    vector<vector<int>> dp;
    
    int maxSubArrayUtil(vector<int>& nums,int index,bool pick)
    {
        if(index>=nums.size())
        {
            return pick?0:INT_MIN;
        }
        
        // if(umap.count(index) && umap[index].count(pick))
        // {
        //     return umap[index][pick];
        // }
        
        if(dp[index][pick]!=-1)
        {
            return dp[index][pick];
        }
        
        if(pick)
        {
            int exclude=0; //once excluded after picking we stop
            int include=nums[index]+maxSubArrayUtil(nums,index+1,pick);
            
            // return max(exclude,include);
            
            // return umap[index][pick]=max(exclude,include);
            return dp[index][pick]=max(exclude,include);
        }
        
        int exclude=maxSubArrayUtil(nums,index+1,pick);
        int include=nums[index]+maxSubArrayUtil(nums,index+1,!pick);
        
        // return max(exclude,include);
        
        // return umap[index][pick]=max(exclude,include);
        return dp[index][pick]=max(exclude,include);
    }
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n=nums.size();
        
        dp.assign(n+1,vector<int>(2,-1));
        
        return maxSubArrayUtil(nums,0,false);
    }
};