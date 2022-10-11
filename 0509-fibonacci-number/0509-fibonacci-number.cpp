class Solution 
{
public:
    int fibonacci[31];
    
    Solution()
    {
        fill(fibonacci,fibonacci+31,-1);
    }
    
    int fib(int n) 
    {
        if(n<=1)
        {
            return n;
        }
        
        if(fibonacci[n]!=-1)
        {
            return fibonacci[n];
        }
        
        fibonacci[n]=fib(n-1)+fib(n-2);
        
        return fibonacci[n];
    }
};