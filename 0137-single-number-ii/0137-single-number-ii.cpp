class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        unordered_map<int,int> umap;
        
        for(auto x:nums)
        {
            umap[x]++;
        }
        
        for(auto x:umap)
        {
            if(x.second==1)
            {
                return x.first;
            }
        }
        
        return 0;
    }
};