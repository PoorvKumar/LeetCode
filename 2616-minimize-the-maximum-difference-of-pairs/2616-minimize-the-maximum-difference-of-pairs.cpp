class Solution
{
private:
    int countPairs(vector<int>& nums,int val)
    {
        int count=0;
        
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i+1]-nums[i]<=val)
            {
                count++;
                i++;
            }
        }
        
        return count;
    }
public:
    int minimizeMax(vector<int>& nums,int p)
    {
        sort(nums.begin(),end(nums));
        
        int low=0;
        int high=nums.back()-nums.front();
        int mid=(low+high)/2;
        
        while(low<high)
        {
            if(countPairs(nums,mid)>=p)
            {
                high=mid;
            }
            else
            {
                low=mid+1;
            }
            
            mid=(low+high)/2;
        }
        
        return mid;
    }
};

// class Solution 
// {
// private:
//     unordered_map<int,unordered_map<int,int>> umap;
    
//     int minimizeMaxUtil(vector<int>& nums,int index,int p)
//     {
//         if(p==0)
//         {
//             return 0;
//         }
        
//         if(index>=nums.size()-1)
//         {
//             return INT_MAX;
//         }
        
//         if(umap.count(index) && umap[index].count(p))
//         {
//             return umap[index][p];
//         }
        
//         int exclude=minimizeMaxUtil(nums,index+1,p);
//         int include=minimizeMaxUtil(nums,index+2,p-1);
//         include=max(abs(nums[index]-nums[index+1]),include);
        
//         // return min(exclude,include); //Recursion Solution
//         //TC: O(2^n) //as 2(exclude,include) Recursion calls for every index
//         //SC: O(n*p)+O(n)auxiliary stack space
        
//         return umap[index][p]=min(exclude,include); //Top-Down DP approach -> Recursion+ Memoization
//         //TC: O(n*p) //as for every index for every p Recursion calls Memoized
//         //SC: O(n*p)+O(n)auxiliary stack space
//     }
// public:
//     int minimizeMax(vector<int>& nums, int p) 
//     {
//         sort(nums.begin(),end(nums));
        
//         // return minimizeMaxUtil(nums,0,p);
        
//         int n=nums.size();
        
// //         vector<vector<int>> dp(n+1,vector<int>(p+1,INT_MAX));
        
// //         for(int i=0; i<=n; i++)
// //         {
// //             dp[i][0]=0;
// //         }
        
// //         for(int i=n-2; i>=0; i--)
// //         {
// //             for(int j=1; j<=p; j++)
// //             {
// //                 int exclude=dp[i+1][j];
// //                 int include=dp[i+2][j-1];
// //                 include=max(abs(nums[i]-nums[i+1]),include);
                
// //                 dp[i][j]=min(exclude,include);
// //             }
// //         }
        
// //         return dp[0][p];
        
//         vector<int> curr(p+1,INT_MAX);
//         vector<int> next1(p+1,INT_MAX);
//         vector<int> next2(p+1,INT_MAX);
        
//         curr[0]=0;
//         next1[0]=0;
//         next2[0]=0;
        
//         for(int i=n-2; i>=0; i--)
//         {
//             for(int j=1; j<=p; j++)
//             {
//                 int exclude=next1[j];
//                 int include=next2[j-1];
//                 include=max(abs(nums[i]-nums[i+1]),include);
                
//                 curr[j]=min(exclude,include);
//             }
//             next2=next1;
//             next1=curr;
//         }
        
//         return curr[p];
//     }
// };