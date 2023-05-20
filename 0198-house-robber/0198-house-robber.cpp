class Solution 
{
private:
    unordered_map<int,int> umap; //umap[index]
    
    int robUtil(vector<int>& nums,int index)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        
        if(umap.count(index))
        {
            return umap[index];
        }
        
        int notRob=robUtil(nums,index+1);
        int rob=nums[index]+robUtil(nums,index+2);
        
        // return max(notRob,rob); //Recursive Solution
        //TC: O(2^n) //as 2(notRob,rob) calls for every index
        //SC: O(n)+O(n)auxiliary stack space
        
        return umap[index]=max(notRob,rob); //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n) //as for every index Recursion calls Memoized
        //SC: O(n)+O(n)auxiliary stack space
    }
public:
    int rob(vector<int>& nums) 
    {
        // return robUtil(nums,0);
        
        int n=nums.size();
        vector<int> dp(n+2,0);
        
        for(int i=n-1; i>=0; i--)
        {
            int notRob=dp[i+1];
            int rob=nums[i]+dp[i+2];
            
            dp[i]=max(notRob,rob);
        }
        
        return dp[0];
    }
};