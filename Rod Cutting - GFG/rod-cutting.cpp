//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
    unordered_map<int,unordered_map<int,int>> umap; //umap[index][target]

    int cutRodUtil(int n,int price[],int index,int target)
    {
        if(target==0) //base case
        {
            return 0;
        }
        
        if(index==n-1) //base case
        {
            if(target==n)
            {
                return price[index];
            }
            return INT_MIN;
        }
        
        if(umap.count(index) && umap[index].count(target))
        {
            return umap[index][target];
        }
        
        int notcut=0+cutRodUtil(n,price,index+1,target);
        int cut=INT_MIN;
        if(target>=index+1)
        {
            cut=price[index]+cutRodUtil(n,price,index,target-(index+1));
        }
        
        // return max(notcut,cut); //Recursive Solution
        //TC: O(2^n) //as 2 (notcut,cut) calls for every index
        //SC: O(n)+O(n)auxiliary stack space
        
        return umap[index][target]=max(notcut,cut); //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n*n) //as for every index for every target Recursion calls Memoized
        //SC: O(n*n)+O(n)auxiliary stack space
    }
public:
    int cutRod(int price[], int n) 
    {
        return cutRodUtil(n,price,0,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends