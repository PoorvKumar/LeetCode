class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string,vector<string>> umap;
        
        for(auto s:strs)
        {
            string str=s;
            sort(s.begin(),s.end());
            
            umap[s].push_back(str);
        }
        
        vector<vector<string>> res;
        
        for(auto x:umap)
        {
            res.push_back(x.second);
        }
        
        return res;
    }
};