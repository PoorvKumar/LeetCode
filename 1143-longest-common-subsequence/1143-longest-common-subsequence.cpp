class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap; //umap[index1][index2]
    
    int longestCommonUtil(string& text1,string& text2,int index1,int index2)
    {
        if(index1>=text1.length() || index2>=text2.length()) //base case
        {
            return 0;
        }
        
        if(umap.count(index1) && umap[index1].count(index2))
        {
            return umap[index1][index2];
        }
        
        if(text1[index1]==text2[index2])
        {
            return umap[index1][index2]=1+longestCommonUtil(text1,text2,index1+1,index2+1);
        }
        
        int t1=longestCommonUtil(text1,text2,index1+1,index2);
        int t2=longestCommonUtil(text1,text2,index1,index2+1);
        
        // return max(t1,t2); //Recursive Solution
        //TC: O(2^(n1+n2)) //as 2 (t1,t2) calls for all index in text1 , text2
        //SC: O(n1+n2)+O(n1+n2)auxiliary stack space
        
        return umap[index1][index2]=max(t1,t2); //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n1*n2) //as for evry index in text1 for every index in textt2 Recursion calls Memoized
        //SC: O(n1*n2)+O(n1+n2)auxiliar stack space
    }
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        // return longestCommonUtil(text1,text2,0,0);
        
        int n1=text1.length();
        int n2=text2.length();
        
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        //dp[index1][index2]
        
        for(int i=n1-1; i>=0; i--)
        {
            for(int j=n2-1; j>=0; j--)
            {
                if(text1[i]==text2[j])
                {
                    dp[i][j]=1+dp[i+1][j+1];
                    continue;
                }
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        
        return dp[0][0];
    }
};