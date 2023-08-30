class Solution 
{
public:
    long long minimumReplacement(vector<int>& nums) 
    {
        long long ans=0;
        
        int last=nums.back();
        
        for(int i=nums.size()-2; i>=0; i--)
        {
            if(nums[i]>last)
            {
                int t=nums[i]/last+(nums[i]%last!=0);
                
                last=nums[i]/t;
                
                ans=ans+t-1;
            }
            else
            {
                last=nums[i];
            }
        }
        
        return ans;
    }
};