class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap; //umap[i][j]
    
    int lcsUtil(string& text1,string& text2,int i,int j)
    {
        if(i>=text1.length() || j>=text2.length())
        {
            return 0;
        }
        
        if(umap.count(i) && umap[i].count(j))
        {
            return umap[i][j];
        }
        
        int ans=0;
        
        if(text1[i]==text2[j])
        {
            ans=1+lcsUtil(text1,text2,i+1,j+1);
        }
        else
        {
            int t1=lcsUtil(text1,text2,i+1,j);
            int t2=lcsUtil(text1,text2,i,j+1);
            
            ans=max(t1,t2);
        }
        
        // return ans; //Recursive Solution
        //TC: O(2^(m+n)) //as 2 Recursion calls for every index of text1 for every index of text2
        //SC: O(m+n)+O(m+n)auxiliary stack space
        
        return umap[i][j]=ans; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(m*n) //as for every index in text1 Recursion calls Memoized for every index in text2
        //SC: O(m*n)+O(m+n)auxiliary stack space
    }
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        return lcsUtil(text1,text2,0,0);
    }
};