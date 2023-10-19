class Solution 
{
public:
    bool backspaceCompare(string s, string t) 
    {
        string str="";
        for(auto c:s)
        {
            if(c=='#')
            {
                if(!str.empty())
                {
                    str.pop_back();
                }
            }
            else
            {
                str+=c;
            }
        }
        
        // cout<<str<<endl;
        
        string str1="";
        for(auto c:t)
        {
            if(c=='#')
            {
                if(!str1.empty())
                {
                    str1.pop_back();
                }
            }
            else
            {
                str1+=c;
            }
        }
        
        // cout<<str1<<endl;
        
        return str==str1;
    }
};