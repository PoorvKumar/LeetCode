class Solution 
{
private:
    unsigned long long M=1e9+7;
    vector<vector<int>> dp; //dp[index][steps]
    
    int numWaysUtil(int index,int steps,int n)
    {
        if(steps==0)
        {
            return index==0;
        }
        
        if(index-steps>0)
        {
            return 0;
        }
        
        if(dp[steps][index]!=-1)
        {
            return dp[steps][index];
        }
        
        int stay=numWaysUtil(index,steps-1,n);
        int left=0;
        if(index-1>=0)
        {
            left=numWaysUtil(index-1,steps-1,n);
        }
        
        int right=0;
        if(index+1<n)
        {
            right=numWaysUtil(index+1,steps-1,n);
        }
        
        int ans=(stay%M+left%M+right%M)%M;
        // return ans; //Recursive Solution
        //TC: O(3^n) //as for every step 3 (stay,left,right) Recursion calls made
        //SC: O(n)auxiliary stack space
        
        return dp[steps][index]=ans%M; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(arrLen*steps) //as for every index for every step Recursion calls Memoized
        //SC: O(arrLen*steps)+O(arrLen*steps)auxilary stack space
    }
public:
    int numWays(int steps, int arrLen) 
    {
//         dp.assign(501,vector<int>(501,-1));
        
//         return numWaysUtil(0,steps,arrLen);
        
        dp.assign(501,vector<int>(501,0));
        dp[0][0]=1;
        
        for(int i=1; i<=steps; i++)
        {
            for(int k=min(arrLen-1,500); k>=0; k--)
            {
                if(k-i>0)
                {
                    continue;
                }
                
                int stay=dp[i-1][k];
                
                int left=0;
                if(k-1>=0)
                {
                    left=dp[i-1][k-1];
                }
                
                int right=0;
                if(k+1<min(arrLen,500))
                {
                    right=dp[i-1][k+1];
                }
                
                int ans=(stay%M+left%M+right%M)%M;
                dp[i][k]=ans;
            }
        }
        
        return dp[steps][0]; //Bottom-Up DP approach -> Tabulation
        // TC: O(steps*arrLen)
        // SC: O(steps*arrLen)
        
        vector<int> prev(501,0);
        vector<int> curr(501,0);
        prev[0]=1;
        
        for(int i=1; i<=steps; i++)
        {
            for(int k=min(arrLen-1,500); k>=0; k--)
            {
                if(k-i>0)
                {
                    continue;
                }
                
                int stay=prev[k];
                
                int left=0;
                if(k-1>=0)
                {
                    left=prev[k-1];
                }
                
                int right=0;
                if(k+1<min(arrLen,501))
                {
                    right=prev[k+1];
                }
                
                int ans=(stay%M+left%M+right%M)%M;
                curr[k]=ans;
            }
            prev=curr;
        }
        
        return prev[0]; //Space Optimisation
        //TC: O(steps*arrLen)
        //SC: O(arrLen)
    }
};