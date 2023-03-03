class Solution 
{
private:
    unordered_map<int,unordered_map<int,bool>> umap;
    
    bool canPartitionUtil(vector<int>& nums,int index,int target)
    {
        if(target==0)
        {
            return true;
        }
        
        if(index==nums.size()-1)
        {
            return nums[index]==target;
        }
        
        if(umap.count(index) && umap[index].count(target))
        {
            return umap[index][target];
        }
        
        bool exclude=canPartitionUtil(nums,index+1,target);
        bool include=false;
        
        if(nums[index]<=target)
        {
            include=canPartitionUtil(nums,index+1,target-nums[index]);
        }
        
        // return exclude || include; //Recursive Solution 
        // //TC: O(2^n) as 2 calls for each index (include,exclude)
        // //SC: O(n) auxiliary space
        
        umap[index][target]=exclude || include;
        return umap[index][target]; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n*target) as for every index all possible values of target recursion calls memoized(result stored)
        //sc: O(n*sum) + O(n)auxiliary space
    }
public:
    bool canPartition(vector<int>& nums)
    {
        int sum=accumulate(nums.begin(),nums.end(),0);
        
        if(sum%2!=0)
        {
            return false;
        }
        
        int target=sum/2;
        // return canPartitionUtil(nums,0,target);
        
        int n=nums.size();
        
//         vector<vector<bool>> dp(nums.size(),vector<bool>(target+1,false));
//         //dp[index][target]
        
//         for(int i=0; i<n; i++)
//         {
//             dp[i][0]=true;
//         }
        
//         for(int i=0; i<=target; i++)
//         {
//             if(nums[n-1]==i)
//             {
//                 dp[n-1][i]=true;
//             }
//         }
        
//         for(int i=n-2; i>=0; i--)
//         {
//             for(int j=1; j<=target; j++)
//             {
//                 bool exclude=dp[i+1][j];
//                 bool include=false;
//                 if(j>=nums[i])
//                 {
//                     include=dp[i+1][j-nums[i]];
//                 }
//                 dp[i][j]=exclude || include;
//             }
//         }
        
//         return dp[0][target]; //Bottom-Up DP approach -> Tabulation
//         //TC: O(n*sum)
//         //SC: O(n*sum)
        
        vector<bool> curr(target+1,false);
        vector<bool> prev(target+1,false);
        
        curr[0]=true;
        prev[0]=true;
        
        for(int i=1; i<=target; i++)
        {
            if(nums[n-1]==i)
            {
                prev[i]=true;
            }
        }
        
        for(int i=n-2; i>=0; i--)
        {
            curr.assign(target+1,false);
            
            for(int j=1; j<=target; j++)
            {
                bool exclude=prev[j];
                bool include=false;
                if(j>=nums[i])
                {
                    include=prev[j-nums[i]];
                }
                
                curr[j]=exclude || include;
            }
            prev=curr;
        }
        
        return curr[target]; //Space Optimisation
        //TC: O(n*sum)
        //SC: O(sum)
    }
};