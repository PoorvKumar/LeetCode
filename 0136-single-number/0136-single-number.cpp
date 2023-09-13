class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        unordered_set<int> uset;
        
        for(auto x:nums)
        {
            if(uset.count(x))
            {
                uset.erase(x);
            }
            else
            {
                uset.insert(x);
            }
        }
        
        return *uset.begin();
    }
};