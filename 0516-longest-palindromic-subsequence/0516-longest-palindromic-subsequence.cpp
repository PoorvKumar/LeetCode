class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap; //umap[index1][index2]
    
    int longestCommonUtil(string& s1,string& s2,int index1,int index2)
    {
        if(index1>=s1.length() || index2>=s2.length())
        {
            return 0;
        }
        
        if(umap.count(index1) && umap[index1].count(index2))
        {
            return umap[index1][index2];
        }
        
        if(s1[index1]==s2[index2])
        {
            return umap[index1][index2]=1+longestCommonUtil(s1,s2,index1+1,index2+1);
        }
        
        int t1=longestCommonUtil(s1,s2,index1+1,index2);
        int t2=longestCommonUtil(s1,s2,index1,index2+1);
        
        // return max(t1,t2); //Recursive Solution
        //TC: O(2^(n1+n2)) //as 2 (t1,t2) calls for evry index in s1 for every index in t2
        //SC: O(n1*n2)+O(n1+n2)auxilary stack space
        
        return umap[index1][index2]=max(t1,t2); //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n1*n2) //as for every index in s1 for every index in s2 Recursion calls Memoized
        //SC: O(n1*n2)+O(n1+n2)auxiliary stack space
    }
public:
    int longestPalindromeSubseq(string s) 
    {
        string s1=s;
        reverse(s.begin(),s.end());
        string s2=s;
        
        return longestCommonUtil(s1,s2,0,0);
    }
};