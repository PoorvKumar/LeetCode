class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap; //umap[index1][index2]
    
    int longestCommonUtil(string& s1,string& s2,int index1,int index2)
    {
        if(index1>=s1.length() || index2>=s2.length()) //base case
        {
            return 0;
        }
        
        if(umap.count(index1) && umap[index1].count(index2))
        {
            return umap[index1][index2];
        }
        
        if(s1[index1]==s2[index2])
        {
            // return 1+longestCommonUtil(s1,s2,index1+1,index2+1);
            return umap[index1][index2]=1+longestCommonUtil(s1,s2,index1+1,index2+1);
        }
        
        int t1=longestCommonUtil(s1,s2,index1+1,index2);
        int t2=longestCommonUtil(s1,s2,index1,index2+1);
        
        // return max(t1,t2); //Recursive Solution
        //TC: O(2^(n1+n2)) // as 2 (t1,t2) calls for every index of s1 for every index of s2
        //SC: O(n1*n2)+O(n1+n2)auxiliary stack space
        
        return umap[index1][index2]=max(t1,t2); //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n1*n2) //as for every index in s1 for every index in s2 Recursion calls Memoized
        //SC: O(n1*n2)+O(n1+n2)auxiliary stack space
    }
public:
    int minInsertions(string s) 
    {
        string s1=s;
        reverse(s.begin(),s.end());
        string s2=s;
        
        // return s.length()-longestCommonUtil(s1,s2,0,0);
        
        int n=s.length();
        
//         vector<vector<int>> dp(n+1,vector<int>(n+1,0));
//         //dp[index1][index2]
        
//         for(int i=n-1; i>=0; i--)
//         {
//             for(int j=n-1; j>=0; j--)
//             {
//                 if(s1[i]==s2[j])
//                 {
//                     dp[i][j]=1+dp[i+1][j+1];
//                     continue;
//                 }
//                 dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
//             }
//         }
        
//         return s.length()-dp[0][0]; //Botom-Up DP approach -> Tabulation
//         //TC: O(n1*n2)
//         //SC: O(n1*n2)
        
        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                if(s1[i]==s2[j])
                {
                    curr[j]=1+prev[j+1];
                    continue;
                }
                curr[j]=max(prev[j],curr[j+1]);
            }
            prev=curr;
        }
        
        return s.length()-prev[0]; //Space Optimisation
        //TC: O(n1*n2)
        //SC: O(n2)
        
        //n1==n2 && n==n1 is true
    }
};