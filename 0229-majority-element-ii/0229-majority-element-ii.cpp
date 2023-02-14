class Solution 
{
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        unordered_map<int,int> umap;
        
        vector<int> vec;
        
        for(auto x:nums)
        {
            umap[x]++;
        }
        
        for(auto x:umap)
        {
            if(x.second>nums.size()/3)
            {
                vec.push_back(x.first);
            }
        }
        
        return vec;
    }
};