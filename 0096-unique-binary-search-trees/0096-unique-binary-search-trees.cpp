class Solution 
{
private:
    unordered_map<int,int> umap;
    
    int numTreesUtil(int n)
    {
        if(n==0 || n==1 || n==2)
        {
            if(n==2)
            {
                return 2;
            }
            return 1;
        }
        
        if(umap.count(n))
        {
            return umap[n];
        }
        
        int ans=0;
        
        for(int i=1; i<=n; i++)
        {
            int LST=numTreesUtil(i-1);
            int RST=numTreesUtil(n-i);
            
            ans=ans+LST*RST;
        }
        
        // return ans; //Recursive Solution
        //TC: O(2^n) //as 2 (LST,RST) calls for every root index
        //SC: O(n)+O(n)auxiliary stack space
        
        return umap[n]=ans; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n*n) //as for evry root index Recursion calls Memmoized and for all rotIndex for every n
        //SC: O(n)+O(n)auxiliary stack space
    }
public:
    int numTrees(int n) 
    {
        return numTreesUtil(n);
    }
};