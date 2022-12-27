class Solution 
{
private:
    const long long M=1000000007;
    
    long long int pow(int x,long long n)
    {
        if(n==0)
        {
            return 1;
        }
        if(n==1)
        {
            return x;
        }
        
        long long ans=pow(x,n/2);
        
        if(n%2==0)
        {
            return ans%M*ans%M;
        }
        
        return x%M*ans%M*ans%M;
    }
public:
    long long int countGoodNumbers(long long n) 
    {
        if(n%2==0)
        {
            return pow(20,n/2)%M;
        }
        return 5*pow(20,n/2)%M;
    }
};