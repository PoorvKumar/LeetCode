//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
private:
    unsigned long long M=1e9+7;
public:
    long long subarraySum(long long a[], long long n)
    {
        long long sum=0;
        
        // vector<long long> prefixSum(n,0);
        
        // prefixSum[0]=a[0];
        // for(int i=1; i<n; i++)
        // {
        //     prefixSum[i]=a[i]+prefixSum[i-1];
        // }
        
        // for(int i=0; i<n; i++)
        // {
        //     long long s=0;
        //     for(int j=i; j<n; j++)
        //     {
        //         // s=s+a[j];
        //         // sum+=s;
        //         if(i!=0)
        //         {
        //             s=prefixSum[j]-prefixSum[i-1];
        //         }
        //         else
        //         {
        //             s=prefixSum[j];
        //         }
        //         sum+=s;
        //     }
        // }
        
        for(int i=0; i<n; i++)
        {
            sum=(sum+(a[i]*(i+1)*(n-i)))%M;
            sum=sum%M;
        }
        
        return sum%M; //Brute Force
        //TC: O(n^2)
        //SC: O(1)
    }
};

//{ Driver Code Starts.
int main()
 {
     long long t; 
     cin>>t;
     while(t--)
     {
         long long n; cin>>n;
         long long a[n+5];
         for(long long i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.subarraySum(a, n)<<endl;
     }
    return 0;
}

// } Driver Code Ends