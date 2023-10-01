class Solution 
{
public:
    string reverseWords(string s) 
    {
        string str;
        string res;
        
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]==' ')
            {
                if(!res.empty())
                {
                    res+=" ";
                }
                reverse(str.begin(),str.end());
                res+=str;
                str.clear();
                continue;
            }
            
            str+=s[i];
        }
        
        if(!res.empty())
        {
            res+=" ";
        }
        reverse(str.begin(),str.end());
        res+=str;
        
        return res;
    }
};