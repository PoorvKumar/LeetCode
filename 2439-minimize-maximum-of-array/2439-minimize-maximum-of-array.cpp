class Solution 
{
public:
    int minimizeArrayValue(vector<int>& nums) 
    {
        int n=nums.size();
        
        long long prefixSum=0;
        int ans=0;
        
        for(int i=0; i<n; i++)
        {
            prefixSum=prefixSum+nums[i];
            ans=max(ans,(int)ceil((prefixSum+i)/(i+1)));
        }
        
        return ans;
        
//         for(int i=0; i<n-1; i++) //getting TLE //26 /68 testcases passed
//         {
//             if(nums[i]>=0 && nums[i+1]>nums[i]) //as not decrementing from 0
//             {
//                 int diff=nums[i+1]-nums[i];
//                 int val=diff/2+diff%2;
                
//                 nums[i]=nums[i]+val;
//                 nums[i+1]=nums[i+1]-val;
                
//                 if(i>0 && nums[i]>nums[i-1])
//                 {
//                     i=i-2;
//                 }
//             }
//         }
        
        for(int i=n-1; i>0; i--) //getting TLE
        {
            if(nums[i]>0 && nums[i]>nums[i-1])
            {
                int diff=nums[i]-nums[i-1];
                int val=diff/2+diff%2;
                
                nums[i]=nums[i]-val;
                nums[i-1]=nums[i-1]+val;
                
                if(i<n-1 && nums[i]<nums[i+1])
                {
                    i=i+2;
                }
            }
        }
        
        int maxim=nums[0];
        for(auto x:nums)
        {
            maxim=max(maxim,x);
        }
        
        return maxim;
    }
};