class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int sum=0;
        int maxim=INT_MIN;
        
        for(auto x:nums)
        {
            sum=sum+x;
            maxim=max(maxim,sum);
            
            if(sum<0)
            {
                sum=0;
            }
        }
        
        return maxim;
    }
};