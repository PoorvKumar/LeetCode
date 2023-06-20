class Solution 
{
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        vector<int> vec;
        vec.push_back(-1);
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]%2!=0)
            {
                vec.push_back(i);
            }
        }
        
        vec.push_back(nums.size());
        
        if(vec.size()==2)
        {
            return 0;
        }
        
        int ans=0;
        
        for(int i=1; i<vec.size()-1; i++)
        {
            if(i+k<vec.size())
            {
                ans=ans+(vec[i]-vec[i-1])*(vec[i+k]-vec[i+k-1]);
            }
        }
        
        return ans; //Sliding Window
        //TC: O(n)
        //SC: O(n)
    }
};