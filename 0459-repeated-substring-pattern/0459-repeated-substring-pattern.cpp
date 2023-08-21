class Solution 
{
public:
    bool repeatedSubstringPattern(string s) 
    {
        if(s.length()==1)
        {
            return false;
        }
        
        string str="";
        
        for(int i=0; i<=s.length()/2; i++)
        {
            str=str+s[i];
            if(s.length()%str.length()==0)
            {
                int k=s.length()/str.length();
                k--;
                
                if(k==0)
                {
                    return false; //only one copy of string
                }
                
                string str1=str;
                
                while(k--)
                {
                    str1+=str;
                }
                
                if(str1==s)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};