class Solution 
{
public:
    bool isIsomorphic(string s, string t) 
    {
        unordered_map<char,char> umap;
        unordered_set<char> uset;
        
        for(int i=0; i<s.length(); i++)
        {
            if(umap.count(s[i]))
            {
                if(umap[s[i]]!=t[i])
                {
                    return false;
                }
            }
            else if(uset.count(t[i]))
            {
                return false;
            }
            
            umap[s[i]]=t[i];
            uset.insert(t[i]);
        }
        
        return true;
    }
};