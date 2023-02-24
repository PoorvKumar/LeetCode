//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution
{
private:
    unordered_map<int,unordered_map<int,bool>> umap;
public:
    bool isSubsetSum(vector<int>& arr, int target,int index=0)
    {
        // if(target==0)
        // {
        //     return true;
        // }
        
        // if(index==arr.size()-1)
        // {
        //     return target==arr[arr.size()-1];
        // }
        
        // if(umap.count(index) && umap[index].count(target))
        // {
        //     return umap[index][target];
        // }
        
        // bool exclude=isSubsetSum(arr,target,index+1);
        // bool include=false;
        // if(target>=arr[index])
        // {
        //     include=isSubsetSum(arr,target-arr[index],index+1);
        // }
        
        // // return exclude || include; //Recursive Solution TC:O(2^n) SC:O(n)
        // return umap[index][target]=exclude || include; //Top-Down DP approach -> Recursion + Memoization 
        // //TC:O(n*sum) SC:O(n*sum) + O(n) auxiliary space
        // //still TLE
        
        int n=arr.size();
        
        // vector<vector<bool>> dp(n,vector<bool>(target+1,false)); 
        // //dp[index][target+1]
        // //as two parameters changing index , target
        
        // for(int i=0; i<n; i++)
        // {
        //     dp[i][0]=true; //base case
        // }
        
        // if(arr[n-1]<=target)
        // {
        //     dp[n-1][arr[n-1]]=true; //base case
        // }
        
        // for(int i=n-2; i>=0; i--) //Bottom-Up DP approach -> Tabulation
        // {
        //     for(int j=1; j<=target; j++)
        //     {
        //         bool exclude=dp[i+1][j];
        //         bool include=false;
        //         if(j>=arr[i])
        //         {
        //             include=dp[i+1][j-arr[i]];
        //         }
                
        //         dp[i][j]=exclude || include;
        //     }
        // }
        
        // return dp[index][target]; //TC: O(n*target) SC:O(n*target)
        
        vector<bool> curr(target+1,false);
        vector<bool> prev(target+1,false);
        
        curr[0]=true;
        prev[0]=true;
        
        if(arr[n-1]<=target)
        {
            prev[arr[n-1]]=true;
        }
        
        for(int i=n-2; i>=0; i--)
        {
            curr.assign(target+1,false);
            
            for(int j=1; j<=target; j++)
            {
                bool exclude=prev[j];
                bool include=false;
                if(j>=arr[i])
                {
                    include=prev[j-arr[i]];
                }
                
                curr[j]=exclude || include;
            }
            
            prev=curr;
        }
        
        return curr[target];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends