class Solution 
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> res;
        
        unordered_set<int> uset;
        
        for(auto x:nums1)
        {
            uset.insert(x);
        }
        
        for(auto x:nums2)
        {
            if(uset.count(x))
            {
                res.push_back(x);
                uset.erase(x);
            }
        }
        
        return res;
    }
};