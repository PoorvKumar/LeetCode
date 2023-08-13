class Solution 
{
private:
    vector<int> dp;
    
    bool validPartitionUtil(vector<int>& nums,int index)
    {
        if(index>=nums.size())
        {
            return true;
        }
        
        if(index==nums.size()-1)
        {
            return false;
        }
        
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        
        if(nums[index]==nums[index+1])
        {
            if(validPartitionUtil(nums,index+2))
            {
                // return true;
                return dp[index]=1;
            }
            
            if(nums.size()-index>=3)
            {
                if(nums[index]==nums[index+2])
                {
                    // return validPartitionUtil(nums,index+3);
                    return dp[index]=validPartitionUtil(nums,index+3);
                }
            }
            
            // return false;
            return dp[index]=false;
        }
        
        if(nums.size()-index>=3)
        {
            if(nums[index]+1==nums[index+1] && nums[index]+2==nums[index+2])
            {
                // return validPartitionUtil(nums,index+3);
                return dp[index]=validPartitionUtil(nums,index+3);
            }
        }
        
        // return false;
        return dp[index]=false;
    }
public:
    bool validPartition(vector<int>& nums) 
    {
        dp.assign(nums.size(),-1);
        
        return validPartitionUtil(nums,0);
    }
};