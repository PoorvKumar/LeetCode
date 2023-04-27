class Solution 
{
private:
    int sqrtFun(int n)
    {
        int low=1;
        int high=n;
        int mid=(low+high)/2;
        
        while(low<high)
        {
            if(mid*mid==n)
            {
                return mid;
            }
            else if(mid*mid<n)
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
            mid=(low+high)/2;
        }
        
        return mid-1;
    }
public:
    int bulbSwitch(int n) 
    {
//         if(n==0)
//         {
//             return n;
//         }
        
//         if(n<=3)
//         {
//             return 1;
//         }
        
        int ans=(int)sqrt(n);
        // int ans=sqrtFun(n);
        
        return ans;
    }
};