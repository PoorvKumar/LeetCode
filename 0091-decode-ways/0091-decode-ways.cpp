class Solution 
{
private:
    unordered_map<int,int> umap; //umap[index]
    
    int numDecodingsUtil(string& s,int index)
    {
        if(s[index]=='0') //base case
        {
            return INT_MIN;
        }
        
        if(index>=s.length()) //base case
        {
            return 1;
        }
        
        if(umap.count(index))
        {
            return umap[index];
        }
        
        int ans=0;
        
        if(index<s.length()-1)
        {
            string num=s.substr(index,2);
            int n=stoi(num);
            if(s[index+1]=='0')
            {
                if(n>26)
                {
                    return 0;
                }
                
                return numDecodingsUtil(s,index+2);
            }
            
            if(n<=26)
            {
                ans=numDecodingsUtil(s,index+2);
                if(ans<0)
                {
                    ans=0;
                }
            }
        }
        
        ans=ans+numDecodingsUtil(s,index+1);
        // return ans; //Recursive Solution
        //TC: O(2^n) //as two (two_digit,one_digit) calls for every index
        //SC: O(n)+O(n)auxiliary stack space
        
        return umap[index]=ans; //Top-Down DP apporach -> Recursion + Memoization
        //TC: O(n) //as for every index Recursion calls Memoized
        //SC: O(n)+O(n)auxiliary stack space
    }
public:
    int numDecodings(string s) 
    {
//         int ans=numDecodingsUtil(s,0);
        
//         return ans>=0?ans:0;
        
        int n=s.length();
        
        vector<int> dp(n+1,0);
        //dp[index]
        
        // for(int i=0; i<n; i++) //base case
        // {
        //     if(s[i]=='0')
        //     {
        //         dp[i]=INT_MIN;
        //     }
        // }
        
        dp[n]=1; //base case
        
        for(int i=n-1; i>=0; i--)
        {
            if(s[i]=='0')
            {
                dp[i]=INT_MIN;
                continue;
            }
            
            int ans=0;
            if(i<n-1)
            {
                string num=s.substr(i,2);
                int number=stoi(num);
                
                if(s[i+1]=='0')
                {
                    if(number>26)
                    {
                        dp[i]=0;
                        continue;
                    }
                    dp[i]=dp[i+2];
                    continue;
                }
                
                if(number<=26)
                {
                    ans=dp[i+2];
                    if(ans<0)
                    {
                        ans=0;
                    }
                }
            }
            
            ans=ans+dp[i+1];
            
            dp[i]=ans;
        }
        
        int res=dp[0];
        return res>=0?res:0;
    }
};