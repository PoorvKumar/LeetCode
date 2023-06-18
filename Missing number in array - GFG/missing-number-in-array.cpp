//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int missingNumber(vector<int>& arr, int n) 
    {
        long long sum=0;
        for(auto x:arr)
        {
            // sum=sum+x;
            sum+=x;
        }
        
        long long val=((long long)n*(long long)(n+1))/2;
        
        return val-sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.missingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends