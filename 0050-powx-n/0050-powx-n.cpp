class Solution 
{
public:
    double myPow(double x, int n) 
    {
        if(n==0)
        {
            return 1;
        }
        
        if(n<0)
        {
            double val=myPow(x,n/2);
            return (1/(n%2!=0?x:1)*1.0)*val*val;
        }
        
        double val=myPow(x,n/2);
        
        return (n%2!=0?x:1)*val*val;
    }
};