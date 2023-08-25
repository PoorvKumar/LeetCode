class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> prefix(nums.size(),0);
        vector<int> suffix(nums.size(),0);
        
        int prod=1;
        int sprod=1;
        
        for(int i=0; i<nums.size(); i++)
        {
            prod=prod*nums[i];
            prefix[i]=prod;
            
            sprod=sprod*nums[nums.size()-i-1];
            suffix[nums.size()-i-1]=sprod;
        }
        
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++)
        {
            int val=1;
            if(i>0)
            {
                val=val*prefix[i-1];
            }
            if(i<nums.size()-1)
            {
                val=val*suffix[i+1];
            }
            
            res.push_back(val);
        }
        
        return res;
    }
};