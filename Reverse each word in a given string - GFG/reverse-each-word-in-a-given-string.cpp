//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> stk;
        
        string str="";
        
        for(int i=s.length()-1; i>=0; i--)
        {
            if(s[i]=='.')
            {
                stk.push(str);
                str="";
                continue;
            }
            str=str+s[i];
        }
        
        stk.push(str);
        
        string res="";
        
        while(!stk.empty())
        {
            res=res+stk.top();
            res+='.';
            stk.pop();
        }
        
        res.pop_back();
        
        return res;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends