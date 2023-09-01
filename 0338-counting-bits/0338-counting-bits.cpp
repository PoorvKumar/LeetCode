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
        
        // return n%2+countBitsUtil(n/2); //Recursive Solution
        //TC: O(logn)
        //SC: O(1)
        
        return dp[n]=n%2+countBitsUtil(n/2); //Top-Down DP approach -> Recursion + Memoization
        //TC: O(logn)
        //SC: O(n)
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
        
//         return res; // object of type class bitset<32> appraoach
//         //TC: O(n)
//         //SC: O(n)
        
//         dp.assign(n+1,-1);
        
//         vector<int> res;
        
//         for(int i=0; i<=n; i++)
//         {
//             int count=countBitsUtil(i);
//             res.push_back(count);
//         }
        
//         return res; 
//         //TC: O(nlogn)
//         //SC: O(n)
        
        vector<int> res;
        
        for(int i=0; i<=n; i++)
        {
            int count=0;
            int val=i;
            while(val>0)
            {
                count=count+val%2;
                val=val/2;
            }
            
            res.push_back(count);
        }
        
        return res;
    }
};