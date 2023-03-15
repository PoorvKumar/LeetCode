//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
private:
    int n;
    unordered_map<int,unordered_map<int,int>> umap;
    
    int knapSackUtil(int wt[],int val[],int index,int W)
    {
        if(W==0)
        {
            return 0;
        }
        
        if(index==n-1)
        {
            if(W>=wt[index])
            {
                return val[index];
            }
            
            return 0;
        }
        
        if(umap.count(index) && umap[index].count(W))
        {
            return umap[index][W];
        }
        
        int exclude=knapSackUtil(wt,val,index+1,W);
        int include=0;
        if(W>=wt[index])
        {
            include=val[index]+knapSackUtil(wt,val,index+1,W-wt[index]);
        }
        
        // return max(exclude,include); //Recursive Solution
        //TC: O(2^n) //as 2 calls(include,exclude) for every index ,n index
        //SC: O(n) + O(n) auxiliary space
        
        return umap[index][W]=max(exclude,include);
    }
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    {
        this->n=n;
        
        return knapSackUtil(wt,val,0,W);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends