class Solution 
{
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
    {
        unordered_map<int,vector<int>> umap;
        
        vector<vector<int>> res;
        
        for(int i=0; i<groupSizes.size(); i++)
        {
            umap[groupSizes[i]].push_back(i);
            
            if(umap[groupSizes[i]].size()==groupSizes[i])
            {
                res.push_back(umap[groupSizes[i]]);
                umap.erase(groupSizes[i]);
            }
        }
        
        for(auto x:umap)
        {
            res.push_back(x.second);
        }
        
        return res;
    }
};