class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n=nums.size();
        k=k%n;
        
        if(k==0)
        {
            return ;
        }
        
        vector<int> vec;
        for(int i=n-k; i<n; i++)
        {
            vec.push_back(nums[i]);
        }
        
        while(k--)
        {
            nums.pop_back();
        }
        
        for(auto x:nums)
        {
            vec.push_back(x);
        }
        nums=vec;
        
        return ;
    }
};