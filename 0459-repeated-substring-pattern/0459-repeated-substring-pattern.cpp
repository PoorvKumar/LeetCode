class Solution 
{
public:
    bool repeatedSubstringPattern(string s) 
    {
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
                    return false;
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