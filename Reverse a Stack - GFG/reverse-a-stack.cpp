//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
private:
    void insertAtBottom(stack<int>& stk,int val)
    {
        if(stk.empty())
        {
            stk.push(val);
            return ;
        }
        
        int x=stk.top();
        stk.pop();
        
        insertAtBottom(stk,val);
        
        stk.push(x);
        return ;
    }
    
    void reverseUtil(stack<int>& stk)
    {
        if(stk.empty())
        {
            return ;
        }
        
        int x=stk.top();
        stk.pop();
        
        reverseUtil(stk);
        
        insertAtBottom(stk,x);
        
        return ;
    }
public:
    void Reverse(stack<int>& stk)
    {
        return reverseUtil(stk);
    }
};


//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends