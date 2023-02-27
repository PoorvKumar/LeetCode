class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap; //umap[index][sum]
    
    bool canPartitionUtil(vector<int>& nums,int index,int val,int sum)
    {
        if(val==sum)
        {
            return true;
        }
        
        if(index==nums.size()-1)
        {
            return sum-nums[index]==val+nums[index];
        }
        
        if(umap.count(index) && umap[index].count(sum))
        {
            return umap[index][sum];
        }
        
        //exclude
        bool exclude=canPartitionUtil(nums,index+1,val,sum); 
        //include
        bool include=false;
        if(sum>=nums[index])
        {
            include=canPartitionUtil(nums,index+1,val+nums[index],sum-nums[index]);
        }
        
        // return exclude || include; //Recursive Solution 
        //TC: O(2^n) as two calls include exclude at every index
        //SC: O(n) + O(n) auxiliary space
        
        return umap[index][sum]=exclude || include; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n*sum) as function call at each index (n) && for all possible sum values from sum to 0 (sum)
        //SC: O(n*sum) for every index && every possible value of sum for that index answer memoized
    }
public:
    bool canPartition(vector<int>& nums)
    {
        int val=0;
        int sum=accumulate(nums.begin(),nums.end(),0);
        
        // cout<<sum<<endl;
        
        // return canPartitionUtil(nums,0,val,sum);
        
        int n=nums.size();
        
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        //dp[index][sum]
        
        for(int i=1; i<=sum; i++)
        {
            if((sum%2==0 && i==sum/2) || i-nums[n-1]==sum-i+nums[n-1]) //sum'+val==sum 
            {
                dp[n-1][i]=true; //val==sum //base case sum-nums[index]==val+nums[index] //bae case
            }
        }
        
        for(int i=n-2; i>=0; i--)
        {
            for(int j=0; j<=sum; j++)
            {
                //exclude
                bool exclude=dp[i+1][j];
                
                //include
                bool include=false;
                if(j>=nums[i]) //as cannot take sum 0
                {
                    include=dp[i+1][j-nums[i]];
                }
                
                dp[i][j]=exclude || include;
            }
        }
        
        return dp[0][sum];
    }
};