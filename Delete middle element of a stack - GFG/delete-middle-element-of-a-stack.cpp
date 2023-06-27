//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
private:
    void deleteMidUtil(stack<int>& stk,int  n,int count)
    {
        if(count==n/2)
        {
            stk.pop();
            return ;
        }
        
        int val=stk.top();
        stk.pop();
        
        deleteMidUtil(stk,n,count+1);
        
        stk.push(val);
    }
public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>& s, int sizeOfStack)
    {
        return deleteMidUtil(s,sizeOfStack,0);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends