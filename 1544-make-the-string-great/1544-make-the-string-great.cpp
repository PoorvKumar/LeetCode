class Solution 
{
public:
    string makeGood(string s) 
    {
        if(s=="")
        {
            return s;
        }
        
        for(int i=0; i<s.length()-1; i++)
        {
            if(abs(s[i]-s[i+1])==32 && (s[i]>=65 && s[i]<=90 || s[i]>=97 && s[i]<=122))
            {
                // s[i]='';
                // s[i+1]='';
                // return makeGood(s);
                string str=s.substr(0,i);
                str=str+s.substr(i+2,s.length()-i-2);
                return makeGood(str);
            }
        }
        
        return s;
    }
};