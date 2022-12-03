class Solution 
{
public:
    bool closeStrings(string word1, string word2) 
    {
        if(word1.length()!=word2.length())
        {
            return false;
        }
        
        unordered_map<char,int> umap1;
        unordered_map<char,int> umap2;
        
        for(auto s:word1)
        {
            umap1[s]++;
        }
        for(auto s:word2)
        {
            umap2[s]++;
        }
        unordered_multiset<int> uset1;
        unordered_multiset<int> uset2;
        
        for(auto x:umap1)
        {
            uset1.insert(x.second);
        }
        for(auto x:umap2)
        {
            uset2.insert(x.second);
        }
        
        for(auto x:umap1)
        {
            if(umap2.count(x.first)==0 || uset2.count(x.second)==0)
            {
                return false;
            }
            if(uset2.count(x.second))
            {
                uset2.erase(uset2.find(x.second));
                // uset2.erase(x.second);
            }
        }
        
        for(auto x:umap2)
        {
            if(umap1.count(x.first)==0 || uset1.count(x.second)==0)
            {
                return false;
            }
            if(uset1.count(x.second))
            {
                uset1.erase(uset1.find(x.second));
                // uset1.erase(x.second);
            }
        }
        
        return true;
    }
};