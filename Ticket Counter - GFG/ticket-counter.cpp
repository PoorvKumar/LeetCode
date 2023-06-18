//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution 
{
public:
    int distributeTicket(int N, int K) 
    {
        int low=1;
        int high=N;
        
        bool start=true;
        
        while(high-low>K)
        {
            if(start)
            {
                low=low+K;
            }
            else
            {
                high=high-K;
            }
            start=!start;
        }
        
        return !start?low:high;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends