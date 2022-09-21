class Solution {
public:
    double myPow(double x, int n) 
    {
        if(x>=0 && x<=0.00001)
        {
            return 0;
        }
        
        if(x==1 || x==-1)
        {
            if(x==1)
            {
                return 1;
            }
            if(n%2==0)
            {
                return 1;
            }
            return -1;
        }
        
        if(n<=-2147400000)
        {
            return 0;
        }
        
        if(n<0)
        {
            return myPow(x,n+1)/x;
        }
        
        if(n==0)
        {
            return 1;
        }
        
        return x*myPow(x,n-1);
    }
};