class Solution 
{
private:
    vector<int> dp;
    
    int robUtil(vector<int>& nums,int index)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        
        int notRob=robUtil(nums,index+1);
        int Rob=nums[index]+robUtil(nums,index+2);
        
        // return max(notRob,Rob); //Recursive Solution
        //TC: O(2^n) //as for every index 2(notRob,Rob) Recursion calls
        //SC: O(n)+O(n)auxiliary stack space
        
        return dp[index]=max(notRob,Rob); //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n)
        //SC: O(n)+O(n)auxiliary stack space
    }
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        dp.assign(n+1,-1);
        
        return robUtil(nums,0);
    }
};