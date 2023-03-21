class Solution 
{
private:
    long long calculateSubarrays(unsigned long long n)
    {
//         long long sum=0;
//         for(int i=0; i<n; i++) //TC: O(n)
//         {
//             sum=sum+(n-i);
//         }
        
//         return sum;
        
        return n*n-(n*(n-1))/2; //TC: O(1)
    }
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        long long ans=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==0)
            {
                int j=i+1;
                while(j<nums.size() && nums[j]==0)
                {
                    j++;
                }
                
                ans=ans+calculateSubarrays(j-i);
                i=j-1;
            }
        }
        
        return ans;
    }
};