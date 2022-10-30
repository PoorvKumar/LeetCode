class Solution 
{
private:
    unordered_map<int,int> umap;
public:
    Solution()
    {
        umap.clear();
    }
    
    int climbStairs(int n) 
    {        
        if(n<3)
        {
            return n;
        }
        
        if(umap.count(n)==1)
        {
            return umap[n];
        }
        
        umap[n]=climbStairs(n-1)+climbStairs(n-2);    
        return umap[n];
    }
};