class Solution 
{
private:
    unordered_map<int,int> umap; //umap[index]
    
    int mincostTicketsUtil(vector<int>& days,vector<int>& costs,int index)
    {
        if(index>=days.size())
        {
            return 0;
        }
        
        if(umap.count(index))
        {
            return umap[index];
        }
        
        int one=costs[0]+mincostTicketsUtil(days,costs,index+1);
        
        int k=index;
        while(k<days.size() && days[k]<days[index]+7)
        {
            k++;
        }
        
        int seven=costs[1]+mincostTicketsUtil(days,costs,k);
        
        k=index;
        while(k<days.size() && days[k]<days[index]+30)
        {
            k++;
        }
        
        int thirty=costs[2]+mincostTicketsUtil(days,costs,k);
        
        int ans=min(one,seven);
        ans=min(ans,thirty);
        
        // return ans; //Recursive Solution
        //TC: O(3^n) //as 3 (one,seven,thrity) calls for every index
        //SC: O(n) + O(n)auxilliary stack space
        
        return umap[index]=ans; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n) //as for every index Recursion calls Memoized
        //SC: O(n) + O(n)auxiliary stack space
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        // return mincostTicketsUtil(days,costs,0);
        
        int n=days.size();
        vector<int> dp(n+1,0);
        
        // dp[n-1]=*min_element(costs.begin(),costs.end());
        dp[n]=0; //base case
        
        for(int i=n-1; i>=0; i--)
        {
            int one=costs[0]+dp[i+1];
            
            int k=i;
            while(k<n && days[k]<days[i]+7)
            {
                k++;
            }
            
            // k=k==n?k-1:k;
            int seven=costs[1]+dp[k];
            
            k=i;
            while(k<n && days[k]<days[i]+30)
            {
                k++;
            }
            
            // k=k==n?k-1:k;
            int thirty=costs[2]+dp[k];
            
            int ans=min(one,seven);
            ans=min(ans,thirty);
            
            dp[i]=ans;
        }
        
        return dp[0]; //Bottom-Up DP approach -> Tabulation
        //TC: O(n)
        //SC: O(n)
    }
};