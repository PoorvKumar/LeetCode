class Solution 
{
private:
    vector<vector<vector<int>>> dp; //dp[i][j][k]
    
    bool isInterLeaveUtil(string& s1,string& s2,string& s3,int i,int j,int k)
    {
        if(i>=s1.length() && j>=s2.length())
        {
            return k>=s3.length();
        }
        
        if(k>=s3.length())
        {
            return false;
        }
        
        if(dp[i][j][k]!=-1)
        {
            return dp[i][j][k];
        }
        
        if(i<s1.length() && s1[i]==s3[k])
        {
            if(isInterLeaveUtil(s1,s2,s3,i+1,j,k+1))
            {
                // return true;
                
                return dp[i][j][k]=true;
            }
        }
        
        if(j<s2.length() && s2[j]==s3[k])
        {
            if(isInterLeaveUtil(s1,s2,s3,i,j+1,k+1))
            {
                // return true;
                
                return dp[i][j][k]=true;
            }
        }
        
        // return false; //Recursive Solution
        //TC: O(2^(p+q)) //as for evry index in s1 for every index in s2 Recursion calls
        //SC: O(p+q+r)+O(p+q)auxiliary stack space
        
        return dp[i][j][k]=false; //Top-Down DP aproach -> Recursion + Memoization
        //TC: O(p*q*r) //as for every index in s1 for every index in s2 for every index in s3 Recursion calls Memoized
        //SC: O(p+q+r)+O(p*q*r)+O(p*q*r)auxiliary stack space
    }
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        int p=s1.length();
        int q=s2.length();
        int r=s3.length();
        
        dp.assign(p+1,vector<vector<int>>(q+1,vector<int>(r+1,-1)));
        
        return isInterLeaveUtil(s1,s2,s3,0,0,0);
    }
};