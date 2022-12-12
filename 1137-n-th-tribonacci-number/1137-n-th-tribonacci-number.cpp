class Solution 
{
private:
    unordered_map<int,int> umap;
public:
    int tribonacci(int n) 
    {
        if(n<3)
        {
            return n==0?0:1;
        }
        
        if(umap.count(n))
        {
            return umap[n];
        }
        
        // return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3); //Recursive Solution
        return umap[n]=tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3); //Top-Down DP approach -> Recursion + Memoization
    }
};