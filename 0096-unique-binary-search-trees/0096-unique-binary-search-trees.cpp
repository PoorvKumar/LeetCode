class Solution 
{
private:
    unordered_map<int,int> umap;
    
    int numTreesUtil(int n)
    {
        if(n==0 || n==1 || n==2)
        {
            return n;
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
            
            if(LST==0 || RST==0)
            {
                if(LST==0)
                {
                    ans=ans+RST;
                }
                else
                {
                    ans=ans+LST;
                }
                continue;
            }
            
            ans=ans+LST*RST;
        }
        
        // return ans; //Recursive Solution
        //TC: O(2^n) //as 2 (LST,RST) calls for every index
        //SC: O(n)+O(n)auxiliary stack space
        
        return umap[n]=ans; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(n) //as for every index Recursion calls Memoized
        //SC: O(n)+O(n)auxiliary stack space
    }
public:
    int numTrees(int n) 
    {
        return numTreesUtil(n);
    }
};