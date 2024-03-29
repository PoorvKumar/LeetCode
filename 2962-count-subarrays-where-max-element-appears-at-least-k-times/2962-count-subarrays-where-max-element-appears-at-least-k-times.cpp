class Solution 
{
public:
    long long countSubarrays(vector<int>& nums, int k) 
    {
        vector<int> vec;
        
        int maxim=*max_element(nums.begin(),nums.end());
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==maxim)
            {
                vec.push_back(i);
            }
        }
        
        int n=nums.size();
        long long ans=0;
        
        for(int i=0; i<n-k+1; i++)
        {
            int j=lower_bound(vec.begin(),vec.end(),i)-vec.begin();
            
            int p=j+k-1;
            if(p>=vec.size())
            {
                break;
            }
            
            ans=ans+n-vec[p];
        }
        
        return ans;
    }
};