class Solution 
{
public:
    bool isSubsequence(string& s, string& t) 
    {
        int p=0;
        int r=0;
        
        while(p<s.length() && r<t.length())
        {
            if(s[p]==t[r])
            {
                p++;
                r++;
            }
            else
            {
                r++;
            }
        }
        
        if(r>=t.length() && p<s.length())
        {
            return false;
        }
        
        return true;
    }
};