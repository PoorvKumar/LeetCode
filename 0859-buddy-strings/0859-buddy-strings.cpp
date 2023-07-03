class Solution 
{
public:
    bool buddyStrings(string s, string goal) 
    {
        if(s.length()!=goal.size())
        {
            return false;
        }
        
        vector<int> vec(26,0);
        for(int i=0; i<s.length(); i++)
        {
            vec[s[i]-'a']++;
            vec[goal[i]-'a']--;
        }
        
        for(auto x:vec)
        {
            if(x!=0)
            {
                return false;
            }
        }
        
        int count=0;
        
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]!=goal[i])
            {
                count++;
            }
        }
        
        // cout<<count<<endl;
        
        if(count==2)
        {
            return true;
        }
        
        if(count==0)
        {
            unordered_map<char,int> umap;

            for(auto c:s)
            {
                umap[c]++;
            }

            for(auto x:umap)
            {
                if(x.second>=2)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};