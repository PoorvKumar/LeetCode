class Solution 
{
private:
    unordered_map<int,unordered_map<int,unordered_map<int,bool>>> umap; //umap[i][j][k]
    
    bool isInterleaveUtil(string& s1,string& s2,string& s3,int i,int j,int k)
    {
        if(i==s1.length() && j==s2.length() && k==s3.length())
        {
            return true;
        }
        
        if(umap.count(i) && umap[i].count(j) && umap[i][j].count(k))
        {
            return umap[i][j][k];
        }
        
        bool ans=false;
        
        if(i<s1.length() && s1[i]==s3[k])
        {
            ans=isInterleaveUtil(s1,s2,s3,i+1,j,k+1);
            
            if(ans)
            {
                // return true;
                return umap[i][j][k]=ans;
            }
        }
        
        if(j<s2.length() && s2[j]==s3[k])
        {
            ans=isInterleaveUtil(s1,s2,s3,i,j+1,k+1);
        }
        
        // return ans; //Recursive Solution
        //TC: O(2^(m+n)) //as 2 Recursive calls for every index i, j in object of type class string s1,s2
        //SC: O(n+m+k)+O(m+n)asuxiliary stack space
        
        return umap[i][j][k]=ans; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(m*n*k) //as for every i for every j for every k Recursion calls Memoized
        //SC: O(m*n*k)+O(m*n)auxiliary stack space
    }
public:
    bool isInterleave(string& s1, string& s2, string& s3) 
    {
        if(s1.length()+s2.length()!=s3.length())
        {
            return false;
        }
        
        return isInterleaveUtil(s1,s2,s3,0,0,0);
    }
};