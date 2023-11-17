class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        unordered_map<string,int> umap;
        
        for(auto &x:strs)
        {
            string s="";
            for(int i=0; i<x.length(); i++)
            {
                s+=x[i];
                umap[s]++;
            }
        }
        
        string res;
        int maxim=INT_MIN;
        
        for(auto x:umap)
        {
            if(x.second>maxim)
            {
                maxim=x.second;
            }
        }
        
        if(maxim!=strs.size())
        {
            return "";
        }
        
        for(auto x:umap)
        {
            if(x.second==maxim)
            {
                if(x.first.length()>res.length())
                {
                    res=x.first;
                }
            }
        }
        
        return res;
    }
};