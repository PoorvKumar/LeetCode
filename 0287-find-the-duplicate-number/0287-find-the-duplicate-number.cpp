class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
//         int n=nums.size()-1;
//         int val=(n*(n+1))/2;
        
//         int sum=accumulate(nums.begin(),end(nums),0);
        
//         return sum-val;
        
        vector<int> freq(1e5+2,0);
        
        for(auto x:nums)
        {
            freq[x]++;
            if(freq[x]>1)
            {
                return x;
            }
        }
        
        return -1;
    }
};