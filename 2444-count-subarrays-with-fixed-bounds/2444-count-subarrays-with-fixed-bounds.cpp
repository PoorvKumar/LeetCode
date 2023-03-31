class Solution 
{
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) 
    {
        long long ans=0;
        // int minim=INT_MAX;
        // int maxim=INT_MIN;
        int minKpos=-1;
        int maxKpos=-1;
        int leftbound=-1;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==minK)
            {
                minKpos=i;
            }
            if(nums[i]==maxK)
            {
                maxKpos=i;
            }
            if(nums[i]<minK || nums[i]>maxK)
            {
                leftbound=i;
            }
            
            ans=ans+max(0,min(minKpos,maxKpos)-leftbound);
        }
        
        return ans; //learnt this Two Pointers approach from Solution
    }
};