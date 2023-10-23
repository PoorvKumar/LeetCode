class Solution 
{
public:
    bool isPowerOfFour(int n) 
    {
        if(n<=1)
        {
            return n==1;
        }
        
        if(n%4!=0)
        {
            return false;
        }
        
        return isPowerOfFour(n/4);
    }
};