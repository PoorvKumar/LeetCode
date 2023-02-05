class Solution 
{
private:
    vector<int> pMap;
    int n;
    
    bool checkInclusion(string& s,int i)
    {
        vector<int> sMap(26,0);
        
        for(int j=i; j<i+n; j++)
        {
            sMap[s[j]-'a']++;
        }
        
        // for(auto x:sMap)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        
        for(int i=0; i<26; i++)
        {
            if(pMap[i]!=sMap[i])
            {
                return false;
            }
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> ans;
        
        if(p.length()>s.length())
        {
            return ans;
        }
        
        pMap.assign(26,0);
        for(int i=0; i<p.length(); i++)
        {
            pMap[p[i]-'a']++;
        }
        
        // for(auto x:pMap)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        
        n=p.length();
        
        for(int i=0; i<=s.length()-p.length(); i++)
        {
            if(checkInclusion(s,i))
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};