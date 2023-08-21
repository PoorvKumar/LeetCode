//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    {
        stack<string> stk;
        
        string str="";
        
        for(int i=0; i<s.length(); i++)
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
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends