class Solution 
{
private:
    unordered_map<char,int> umap;
    int n;
    
    bool isPermutation(string& s2,int i)
    {
        unordered_map<char,int> umap1;
        for(int j=i; j<i+n; j++)
        {
            umap1[s2[j]]++;
        }
        
        if(umap1.size()!=umap.size())
        {
            return false;
        }
        
        for(auto x:umap1)
        {
            if(!umap.count(x.first) || umap[x.first]!=x.second)
            {
                return false;
            }
        }
        
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) 
    {
        if(s1.length()>s2.length())
        {
            return false;
        }
        
        n=s1.length();
        
        for(auto x:s1)
        {
            umap[x]++;
        }
        
        for(int i=0; i<=s2.length()-s1.length(); i++)
        {
            // string str=s2.substr(i,s1.length()); //we can pass index to optimise instead of substring of s
            if(isPermutation(s2,i))
            {
                return true;
            }
        }
        
        return false;
    }
};