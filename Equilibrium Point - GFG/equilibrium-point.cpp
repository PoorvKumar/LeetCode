//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends


#include<bits/stdc++.h>

class Solution
{
public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) 
    {
        vector<long long> prefix(n,0);
        
        long long sum=0;
        
        for(int i=0; i<n; i++)
        {
            sum=sum+a[i];
            prefix[i]=sum;
        }
        
        if(n==1)
        {
            return 1;
        }
        
        for(int i=1; i<n; i++)
        {
            if(prefix[i-1]==sum-prefix[i])
            {
                return i+1;
            }
        }
        
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends