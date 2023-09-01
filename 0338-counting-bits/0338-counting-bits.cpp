class Solution 
{
private:
    vector<int> dp;
    
    int countBitsUtil(int n)
    {
        if(n==0)
        {
            return 0;
        }
        
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        
        // return n%2+countBitsUtil(n/2);
        
        return dp[n]=n%2+countBitsUtil(n/2);
    }
public:
    vector<int> countBits(int n) 
    {
//         vector<int> res;
        
//         for(int i=0; i<=n; i++)
//         {
//             bitset<32> bs(i);
//             res.push_back(bs.count());
//         }
        
//         return res;
        
        dp.assign(n+1,-1);
        
        vector<int> res;
        
        for(int i=0; i<=n; i++)
        {
            int count=countBitsUtil(i);
            res.push_back(count);
        }
        
        return res;
    }
};