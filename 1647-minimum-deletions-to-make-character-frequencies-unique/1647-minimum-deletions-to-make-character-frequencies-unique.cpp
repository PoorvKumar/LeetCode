class Solution 
{
public:
    int minDeletions(string s) 
    {
        vector<int> freq(26,0);
        
        for(auto c:s)
        {
            freq[c-'a']++;
        }
        
        map<int,int,greater<int>> mp;
        
        for(int i=0; i<26; i++)
        {
            if(freq[i]!=0)
            {
                mp[freq[i]]++;
            }
        }
        
        int ans=0;
        
        for(auto x:mp)
        {
            if(x.first!=0 && x.second-1>0)
            {
                // cout<<x.first<<endl;
                ans+=x.second-1;
                mp[x.first-1]+=x.second-1;
            }
        }
        
        return ans;
    }
};