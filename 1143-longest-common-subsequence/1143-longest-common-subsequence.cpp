class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap; //umap[x][y]
    
    int longestCommonUtil(string& text1,string& text2,int x,int y)
    {
        // if(x==text1.length()-1 && y==text2.length()-1)
        // {
        //     return text1[x]==text2[y];
        // }
        
        if(x==text1.length()-1 || y==text2.length()-1) //base case
        {
            if(x==text1.length()-1)
            {
                while(y<text2.length())
                {
                    if(text1[x]==text2[y])
                    {
                        return 1;
                    }
                    y++;
                }
                return 0;
            }
            
            while(x<text1.length())
            {
                if(text1[x]==text2[y])
                {
                    return 1;
                }
                x++;
            }
            
            return 0;
        }
        
        if(umap.count(x) && umap[x].count(y))
        {
            return umap[x][y];
        }
        
        if(text1[x]==text2[y])
        {
            return umap[x][y]=1+longestCommonUtil(text1,text2,x+1,y+1);
        }
        
        int t1=longestCommonUtil(text1,text2,x+1,y);
        int t2=longestCommonUtil(text1,text2,x,y+1);
        
        // return max(t1,t2); //Recursive Solution
        
        return umap[x][y]=max(t1,t2); //Top-Down DP approach -> Recursion + Memoization
        //TC: O(x*y) //as for every index in text1 for every indedx in text2 Recursion calls Memoized
        //SC: O(x*y)
    }
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        // return longestCommonUtil(text1,text2,0,0);
        
        if(text1.length()<text2.length())
        {
            text1.swap(text2);
        }
        
        int n1=text1.length();
        int n2=text2.length();
        
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0)); //dp[x][y]
        
        for(int i=0; i<n2; i++) //base case
        {
            dp[n1-1][i]=text1[n1-1]==text2[i];
        }
        
        for(int i=0; i<n1; i++) //base case
        {
            dp[i][n2-1]=text1[i]==text2[n2-1];
        }
        
        for(int i=n1-1; i>=0; i--)
        {
            for(int j=n2-1; j>=0; j--)
            {
                if(text1[i]==text2[j])
                {
                    dp[i][j]=1+dp[i+1][j+1];
                    continue;
                }
                
                int t1=dp[i+1][j];
                int t2=dp[i][j+1];
                
                dp[i][j]=max(t1,t2);
            }
        }
        
        return dp[0][0];
    }
};