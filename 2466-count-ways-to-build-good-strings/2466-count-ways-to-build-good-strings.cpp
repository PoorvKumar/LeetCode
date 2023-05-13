class Solution 
{
private:
    long long M=1e9+7;
    
    unordered_map<int,int> umap; //umap[size]
    
    int countGoodStringsUtil(int low,int high,int z,int o,int size)
    {
        if(size>high)
        {
            return 0;
        }
        
        if(umap.count(size))
        {
            return umap[size];
        }
        
        int ans=size>=low && size<=high?1:0;
        
        int zero=countGoodStringsUtil(low,high,z,o,size+z);
        int one=countGoodStringsUtil(low,high,z,o,size+o);
        
        ans=ans+(zero+one)%M;
        
        // return ans; //Recursive Solution
        //TC: O(2^n) //as 2(zero,one) calls for every index
        //SC: O(high)+O(high)auxiliary stack space
        
        return umap[size]=ans; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(high) //as for evry size Recursion calls Memoized
        //SC: O(high)+O(high)auxiliary stack space
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        // return countGoodStringsUtil(low,high,zero,one,0);
        
        vector<int> dp(high+1,0);
        //dp[size]
        
        for(int i=high; i>=0; i--)
        {
            int ans=i>=low && i<=high?1:0;
            
            int zeroAppend=0;
            if(i+zero<=high)
            {
                zeroAppend=dp[i+zero];
            }
            
            int oneAppend=0;
            if(i+one<=high)
            {
                oneAppend=dp[i+one];
            }
            
            dp[i]=ans+(zeroAppend+oneAppend)%M;
        }
        
        return dp[0]; //Bottom-Up DP approach -> Tabulation
        //TC: O(high)
        //SC: O(high)
    }
};