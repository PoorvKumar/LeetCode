class Solution 
{
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        unordered_map<int,int> umap;
        
        for(auto x:nums)
        {
            umap[x]++;
        }
        
        int val=floor(nums.size()/(3*1.0));
        
        vector<int> res;
        for(auto x:umap)
        {
            if(x.second>val)
            {
                res.push_back(x.first);
            }
        }
        
        return res;
    }
};