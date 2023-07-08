class Solution 
{
private:
    vector<int> dp;
    
    bool canJumpUtil(vector<int>& nums,int index)
    { 
        if(nums[index]+index>=nums.size()-1)
        {
            return true;
        }
        
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        
        for(int i=1; i<nums[index]+1; i++)
        {
            if(canJumpUtil(nums,index+i))
            {
                dp[index]=1; 
                return true; //Top-Down DP approach -> recursion + Memoization
                //TC: O(n) //as for every index Recursion calls Memoized
                //SC: O(n)+O(n)auxiliary stack space
            }
        }
        
        dp[index]=0;
        return false; //Recursive Solution
        //TC: O(k^n) //as k Recursion calls for every index
        //SC: O(n)+O(n)auxiliary stack space
    }
public:
    bool canJump(vector<int>& nums) 
    {
        dp.assign(nums.size(),-1);
        
        return canJumpUtil(nums,0);
    }
};