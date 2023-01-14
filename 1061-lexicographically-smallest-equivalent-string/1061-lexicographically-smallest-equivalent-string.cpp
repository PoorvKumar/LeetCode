class Solution 
{
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) 
    {
        // unordered_map<char,char> umap;
        unordered_map<char,set<char>> umap;
        
        for(int i=0; i<s1.length(); i++)
        {
            char p=s1[i];
            char q=s2[i];
            
            umap[p].insert({p,q});
            umap[q].insert({p,q});
            
            for(auto x:umap[p])
            {
                for(auto y:umap[x])
                {
                    umap[y].insert(q);
                    umap[q].insert(y);
                }
            }
            for(auto x:umap[q])
            {
                for(auto y:umap[x])
                {
                    umap[y].insert(p);
                    umap[p].insert(y);
                }
            }
        }
        
        // for(auto x:umap)
        // {
        //     // cout<<x.first<<" "<<x.second<<endl;
        //     cout<<x.first<<" "<<*x.second.begin()<<endl;
        // }
        
        for(auto &x:baseStr)
        {
            if(!umap.count(x))
            {
                // umap[x]=x;
                umap[x].insert(x);
            }
            // x=umap[x];
            x=*umap[x].begin();
        }
        
        return baseStr;
    }
};