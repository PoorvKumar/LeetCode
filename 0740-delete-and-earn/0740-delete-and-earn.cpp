class Solution 
{
private:
    unordered_map<int,int> umap;
    unordered_map<int,int> ans;
    
    int deleteAndEarnUtil(vector<int>& vec,int index,int cost,unordered_set<int>& uset)
    {
        if(index>=vec.size())
        {
            return cost;
        }
        
        // if(ans.count(index)) //wrionog answer
        // {
        //     return ans[index];
        // }
        
        int val=vec[index]*umap[vec[index]]; //Time Complexity : O(2^n) every time 2 calls for deleted notdeleted
        
        int deleted=0;
        if(!uset.count(vec[index]-1))
        {
            uset.insert(vec[index]);
            deleted=deleteAndEarnUtil(vec,index+1,cost+val,uset);
            uset.erase(vec[index]);
        }
        else
        {
            deleted=0;
        }
        
        int notdeleted=deleteAndEarnUtil(vec,index+1,cost,uset);
        
        return max(deleted,notdeleted); //getting TLE 
        
        // ans[index]=max(deleted,notdeleted);
        // return ans[index];
    }
public:
    int deleteAndEarn(vector<int>& nums)
    {
        // unordered_map<int,int> umap;
//         for(int i=0; i<nums.size(); i++)
//         {
//             umap[nums[i]]++;
//         }
        
//         if(umap.size()==1)
//         {
//             return nums[0]*umap[nums[0]];
//         }
        
//         int n=umap.size();
        
//         vector<int> vec;
//         for(auto x:umap)
//         {
//             vec.push_back(x.first);
//         }
        
//         sort(vec.begin(),vec.end());
        // int maxim=0;
        
        // vector<int> dp(n,0);
        // dp[0]=vec[0]*umap[vec[0]];
        
//         int i=1;

//         if(vec[1]==vec[0]+1)
//         {
//             dp[1]=vec[1]*umap[vec[1]];
//             i++;
//         }

//         maxim=max(dp[0],dp[1]);

//         for( ; i<n; i++) //Time Complexity: O(n^2)
//         {
//             int x=vec[i]*umap[vec[i]];
//             if(vec[i]!=vec[i-1]+1)
//             {
//                 int maxLast=0;
//                 for(int j=0; j<=i-1; j++) //maximum value till i-1
//                 {
//                     maxLast=max(maxLast,dp[j]);
//                 }
//                 dp[i]=maxLast+x;
//                 // dp[i]=dp[i-1]+x;
//             }
//             else
//             {
//                 int maxLast=0;
//                 for(int j=0; j<i-1; j++) //maximum value till i-2 
//                 {
//                     maxLast=max(maxLast,dp[j]);
//                 }
//                 dp[i]=maxLast+x;
//                 // dp[i]=dp[i-2]+x;
//             }
//             maxim=max(maxim,dp[i]);
//         }

//         return maxim;
//         // return max(dp[n-1],dp[n-2]);
        
// //         unordered_set<int> uset;
        
// //         return deleteAndEarnUtil(vec,0,0,uset);
        
        int maxim=*max_element(nums.begin(),nums.end());
        // int maxim=vec[vec.size()-1]; //largest element
        vector<int> dp(maxim+1,0);
        
        for(auto x:nums)
        {
            dp[x]=dp[x]+x;
        }
        
        for(int i=2; i<=maxim; i++)
        {
            // int x=vec[i]*umap[vec[i]];
            dp[i]=max(dp[i-1],dp[i-2]+dp[i]);
        }
        
        // return max(dp[n-1],dp[n-2]);
        return dp[maxim];
    }
};