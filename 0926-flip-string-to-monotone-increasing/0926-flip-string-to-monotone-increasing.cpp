class Solution 
{
public:
    int minFlipsMonoIncr(string s)
    {
//         int i=0;
//         while(i<s.length() && s[i]!='1')
//         {
//             i++;
//         }
        
//         int j=s.length()-1;
//         while(j>i && s[j]=='1')
//         {
//             j--;
//         }
        
//         int one=0;
//         int zero=0;
        
//         for( ; i<=j; i++)
//         {
//             s[i]=='1'?one++:zero++;
            
//         }
        
//         int ans=min(zero,one);
        
//         return min(zero,one);
        
        vector<int> dp(s.length(),0);
        dp[0]=0;
        
        int ones=s[0]=='1'?1:0;
        
        for(int i=1; i<s.length(); i++)
        {
            if(s[i]=='0')
            {
                dp[i]=min(ones,dp[i-1]+1);
            }
            else
            {
                dp[i]=dp[i-1];
                ones++;
            }
        }
        
        return dp[s.length()-1]; 
    }
};