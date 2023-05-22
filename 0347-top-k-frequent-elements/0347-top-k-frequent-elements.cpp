class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> umap;
        
        for(int i=0; i<nums.size(); i++)
        {
            umap[nums[i]]++;
        }
        
        vector<pair<int,int>> vec;
        
        for(auto x:umap)
        {
            vec.push_back({x.second,x.first});
        }
        
        sort(vec.begin(),vec.end(),greater<pair<int,int>>());
        
        vector<int> res;
        
        for(int i=0; i<k; i++)
        {
            res.push_back(vec[i].second);
        }
        
        return res;
    }
};