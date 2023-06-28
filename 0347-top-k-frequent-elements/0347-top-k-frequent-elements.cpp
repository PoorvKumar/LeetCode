class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> umap;
        
        for(auto x:nums)
        {
            umap[x]++;
        }
        
        for(auto x:umap)
        {
            pq.push({x.second,x.first});
        }
        
        vector<int> res;
        
        while(k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
            if(pq.empty())
            {
                break;
            }
        }
        
        return res;
    }
};