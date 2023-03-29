class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap; //umap[index][time]
    
    int maxSatisfactionUtil(vector<int>& satisfaction,int index,int time)
    {
        if(index==satisfaction.size()-1)
        {
            if(time*satisfaction[index]>0)
            {
                return time*satisfaction[index];
            }
            return 0;
        }
        
        if(umap.count(index) && umap[index].count(time))
        {
            return umap[index][time];
        }
        
        int exclude=0+maxSatisfactionUtil(satisfaction,index+1,time);
        int include=time*satisfaction[index]+maxSatisfactionUtil(satisfaction,index+1,time+1);
        
        // return max(exclude,include); //Recursive Solution
        //TC: O(2^n) //as 2 (incldue,exlcude) calls for every index
        //SC: O(n) + O(n)auxiliary space
        
        return umap[index][time]=max(exclude,include); //Top-Dpown DP approach -> Recursion + Memoization
        //TC: O(n*time) //as for every index for every time Recursion calls Memoized
        //SC: O(n*time) + O(n)auxiliary stack space
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) 
    {
        sort(satisfaction.begin(),satisfaction.end());
        
        // return maxSatisfactionUtil(satisfaction,0,1);
        
        int n=satisfaction.size();
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        //dp[index][time]
        
        for(int i=1; i<=n; i++) //base case
        {
            int val=i*satisfaction[n-1];
            if(val>0)
            {
                dp[n-1][i]=val;
            }
        }
        
        for(int i=n-2; i>=0; i--)
        {
            for(int j=1; j<n; j++)
            {
                int exclude=0+dp[i+1][j];
                int include=j*satisfaction[i]+dp[i+1][j+1];
                
                dp[i][j]=max(exclude,include);
            }
        }
        
        return dp[0][1];
    }
};