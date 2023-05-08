class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap; //umap[index][prev]
    
    int lengthOfLISUtil(vector<int>& nums,int index,int prev)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        
        if(umap.count(index) && umap[index].count(prev))
        {
            return umap[index][prev];
        }
        
        int exclude=lengthOfLISUtil(nums,index+1,prev);
        int include=0;
        
        if(prev==0 || nums[index]>nums[prev-1])
        {
            int i=index+1;
            // while(i<nums.size() && nums[index]>=nums[i]) //adds to time complexity
            // {
            //     i++;
            // }
            
            include=1+lengthOfLISUtil(nums,index+1,index+1);
        }
        
        // return max(exclude,include); //Recursive Solution
        //TC: O(2^n) //as 2 (exclude,include) calls for every index
        //SC: O(n)+O(n)auxiliary stack space
        
        return umap[index][prev]=max(exclude,include); //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n*n) //as for every index for evry prev Recursion calls Memoized
        //SC: O(n*n)+O(n)auxiliary stack space
    }
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        // return lengthOfLISUtil(nums,0,0); //getting TLE
        
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0)); //dp[index][prev]
        
        //shifting of index 0->1
        
        for(int i=n-1; i>=0; i--) //index
        {
            for(int j=n; j>=0; j--) //prev -> will be always less than or equal to i+1
            {
                int exclude=dp[i+1][j];
                int include=0;
                
                if(j==0 || nums[i]>nums[j-1])
                {
                    // int k=i+1;
                    // while(k<nums.size() && nums[i]>=nums[k])
                    // {
                    //     k++;
                    // }
                    
                    include=1+dp[i+1][i+1];
                }
                
                dp[i][j]=max(exclude,include);
            }
        }
        
        return dp[0][0]; //Bottom-Up DP approach -> Tabulation
        //TC: O(n*n)
        //SC: O(n*n)
        
//         vector<int> curr(n+1,0);
//         vector<int> prev(n+1,0);
        
//         for(int i=n-1; i>=0; i--) //index
//         {
//             for(int j=i+1; j>=0; j--) //prev
//             {
//                 int exclude=prev[j];
//                 int include=0;
                
//                 if(j==0 || nums[i]>nums[j-1])
//                 {
//                     include=1+prev[i+1];
//                 }
                
//                 curr[j]=max(exclude,include);
//             }
//             prev=curr;
//         }
        
//         return prev[0];
    }
};