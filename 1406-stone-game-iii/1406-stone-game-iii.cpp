class Solution 
{
private:
    unordered_map<int,unordered_map<bool,int>> umap; //umap[index][alice]
    
    int stoneGameIIIUtil(vector<int>& stoneValue,int index,bool alice)
    {
        if(index>=stoneValue.size())
        {
            return 0;
        }
        
        if(umap.count(index) && umap[index].count(alice))
        {
            return umap[index][alice];
        }
        
        int ans=alice?INT_MIN:INT_MAX;
        int sum=0;
        
        for(int i=1; i<=3; i++)
        {
            sum=alice?sum+stoneValue[index+i-1]:0;
            int val=sum+stoneGameIIIUtil(stoneValue,index+i,!alice);
            
            ans=alice?max(ans,val):min(ans,val);
            
            if(index+i>=stoneValue.size())
            {
                break;
            }
        }
        
        // return ans; //Recursive Solution
        //TC: O(2*3^n) //as 3 Recursion calls for every index and twice for each for Alice and Bob
        //SC: O(n)+O(n)auxiliary stack space
        
        return umap[index][alice]=ans; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n*2) //as for every index for every Alice and Bob Recursion calls Memoized
        //SC: O(n*2)+O(n)auxiliary stack space
    }
public:
    string stoneGameIII(vector<int>& stoneValue) 
    {
        // int Alice=stoneGameIIIUtil(stoneValue,0,true);
        // int Bob=stoneGameIIIUtil(stoneValue,0,false);
        
        int n=stoneValue.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        //dp[index][alice]
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=1; j>=0; j--)
            {
                int ans=j==1?INT_MIN:INT_MAX;
                int sum=0;
                
                for(int k=1; k<=3; k++)
                {
                    sum=j==1?sum+stoneValue[i+k-1]:0;
                    int val=sum+(i+k<=n?dp[i+k][!j]:0);
                    
                    ans=j==1?max(ans,val):min(ans,val);
                    
                    if(i+k>=n)
                    {
                        break;
                    }
                }
                
                dp[i][j]=ans;
            }
        }
        
        int Alice=dp[0][1];
        
        int totalScore=accumulate(stoneValue.begin(),stoneValue.end(),0);
        int Bob=totalScore-Alice;
        // cout<<totalScore<<" "<<Alice<<" "<<Bob<<endl;
        
        if(Alice>Bob)
        {
            return "Alice";
        }
        
        if(Alice<Bob)
        {
            return "Bob";
        }
        
        return "Tie"; //Bottom-Up DP approach -> Tabulation
        //TC: O(n*2)
        //SC: O(n*2)
    }
};