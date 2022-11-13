class Solution 
{
public:
    string reverseWords(string s) 
    {
        stringstream ss;
        ss<<s;
        
        string x;
        
        stack<string> stk;
        
        while(ss>>x)
        {
            stk.push(x);
        }
        
        s.clear();
        
        while(!stk.empty())
        {
            s=s+stk.top()+" ";
            stk.pop();
        }
        s.pop_back();
        
        return s;
    }
};