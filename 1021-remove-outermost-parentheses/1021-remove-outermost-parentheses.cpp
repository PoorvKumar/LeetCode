class Solution 
{
public:
    string removeOuterParentheses(string s) 
    {
        string res="";
        string str="";
        
        int k=0;
        
        for(int i=0; i<s.length(); i++)
        {
            if(k==0 && !str.empty())
            {
                for(int j=1; j<str.length()-1; j++)
                {
                    res+=str[j];
                }
                str="";
            }
            
            // if(k!=0)
            // {
            //     str+=s[i];
            // }
            str+=s[i];
            
            if(s[i]=='(')
            {
                k++;
            }
            else
            {
                k--;
            }
        }
        
        for(int j=1; j<str.length()-1; j++)
        {
            res+=str[j];
        }
        return res;
    }
};