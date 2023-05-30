//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int LargButMinFreq(int arr[], int n) 
    {
        map<int,int> mp;
        
        int maxim=0;
        
        for(int i=0; i<n; i++)
        {
            mp[arr[i]]++;
            maxim=max(maxim,mp[arr[i]]);
        }
        
        // for(auto x:mp)
        // {
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        
        vector<int> vec(maxim+1,INT_MIN);
        
        for(auto x:mp)
        {
            vec[x.second]=max(vec[x.second],x.first);
        }
        
        // for(auto x:vec)
        // {
        //     cout<<x<<" ";
        // }
        
        for(auto x:vec)
        {
            if(x!=INT_MIN)
            {
                return x;
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends