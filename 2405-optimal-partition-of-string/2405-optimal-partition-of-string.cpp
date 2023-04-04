class Solution 
{
public:
    int partitionString(string s) 
    {
        int ans=0;
        unordered_set<char> uset;
        
        for(int i=0; i<s.length(); i++)
        {
            if(uset.count(s[i]))
            {
                ans++;
                uset.clear();
            }
            uset.insert(s[i]);
        }
        
        if(!uset.empty())
        {
            ans++;
        }
        
        return ans;
    }
};