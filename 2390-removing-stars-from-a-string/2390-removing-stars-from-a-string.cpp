class Solution 
{
public:
    string removeStars(string s) 
    {        
        stack<char> stk;
        
        string ans="";
        
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='*')
            {
                // stk.pop();
                ans.pop_back();
                continue;
            }
            // stk.push(s[i]);
            ans.push_back(s[i]);
        }
        
//         string ans="";
        
//         while(!stk.empty())
//         {
//             ans=ans+stk.top();
//             stk.pop();
//         }
        
//         reverse(ans.begin(),ans.end());
        
        return ans;
    }
};