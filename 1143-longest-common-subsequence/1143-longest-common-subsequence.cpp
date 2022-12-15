class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap;
    
    int topDownDP(string s1,string s2,int i,int j)
    {
        if(i<0 || j<0)
        {
            return 0;
        }
        
        if(umap.count(i) && umap[i].count(j))
        {
            return umap[i][j];
        }
        
        if(s1[i]==s2[j]) 
        {
            umap[i][j]=1+topDownDP(s1,s2,i-1,j-1); //Top-Down DP -> Recursion + Memoization
            return umap[i][j];
            
            // return 1+topDownDP(s1,s2,i-1,j-1); //Recursive Solution Time Complexity: Exponential
        }
        else
        {
            umap[i][j]=max(topDownDP(s1,s2,i-1,j),topDownDP(s1,s2,i,j-1));
            return umap[i][j];
            
            // return max(topDownDP(s1,s2,i-1,j),topDownDP(s1,s2,i,j-1));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        string s1;
        string s2;
        if(text1.length()<text2.length())
        {
            s1=text2;
            s2=text1;
        }
        else
        {
            s1=text1;
            s2=text2;
        }
        
        // return topDownDP(s1,s2,s1.length()-1,s2.length()-1);
        
        vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,0));
        
        for(int i=1; i<s1.length()+1; i++) //Botttom-UP DP approach -> Tabulation
        {
            for(int j=1; j<s2.length()+1; j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[s1.length()][s2.length()];
    }
};