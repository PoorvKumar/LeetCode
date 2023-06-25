class Solution 
{
private:
    unordered_map<int,int> umap;
    
    int climbStairsUtil(int n)
    {      
        if(n<=2)
        {
            return n;
        }
        
        if(umap.count(n))
        {
            return umap[n];
        }
        
        int oneStep=climbStairsUtil(n-1);
        int twoStep=climbStairsUtil(n-2);
        
        // return oneStep+twoStep;
        
        return umap[n]=oneStep+twoStep;
    }
public:
    int climbStairs(int n) 
    {
        return climbStairsUtil(n);
    }
};