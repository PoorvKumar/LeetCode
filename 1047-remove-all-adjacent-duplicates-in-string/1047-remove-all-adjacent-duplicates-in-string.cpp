class Solution
{
public:
    string removeDuplicates(string s)
    {
        // stack<char> stack;
        // deque<char> dq;
        
        for(int i=0; i<s.length()-1; i++)
        {
            if(s[i]==s[i+1])
            {
                if(s.length()==2)
                {
                    s="";
                    return s;
                }
                
                s.erase(i,2);                
                
                // return removeDuplicates(s);
                
                if(i>0)
                {
                    i=i-2;
                }
                else
                {
                    i=-1;
                }
                // i=-1;
            }
        }
        
        return s;
    }
};