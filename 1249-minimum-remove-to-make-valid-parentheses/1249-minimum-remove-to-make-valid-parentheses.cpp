class Solution 
{
private:
    string removeInvalidPar(string& s)
    {
        stack<char> stk;
        string res;
        
        for(auto x:s)
        {
            if(x==')')
            {
                if(stk.empty())
                {
                    continue;
                }
                
                stk.pop();
            }
            else if(x=='(')
            {
                stk.push('(');
            }
            
            res+=x;
        }
        
        return res;
    }
    
    void reverseString(string& s)
    {
        reverse(s.begin(),s.end());
        
        for(auto &x:s)
        {
            if(x=='(')
            {
                x=')';
            }
            else if(x==')')
            {
                x='(';
            }
        }
    }
public:
    string minRemoveToMakeValid(string s) 
    {
        string res=removeInvalidPar(s);
        reverseString(res);
        res=removeInvalidPar(res);
        reverseString(res);
        
        return res;
    }
};