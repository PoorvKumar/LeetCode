class Solution 
{
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<vector<int>> ans(2,vector<int>());
        
        unordered_set<int> uset1,uset2;
        
        for(auto x:nums1)
        {
            uset1.insert(x);
        }
        
        for(auto x:nums2)
        {
            uset2.insert(x);
        }
        
        for(auto x:uset1)
        {
            if(!uset2.count(x))
            {
                ans[0].push_back(x);
            }
        }
        
        for(auto x:uset2)
        {
            if(!uset1.count(x))
            {
                ans[1].push_back(x);
            }
        }
        
        return ans;
    }
};