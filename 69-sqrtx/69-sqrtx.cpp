class Solution {
public:
    int mySqrt(int x) 
    {
        unsigned long low=1;
        unsigned long high=x;
        unsigned long mid=(low+high)/2;
        // unsigned int M=1000000007;
        
        while(low<=high)
        {
            unsigned long sqr=mid*mid;
            
            if(sqr==x)
            {
                return mid;
            }
            else if(sqr>x)
            {
                high=mid-1;
                mid=(low+high)/2;
            }
            else 
            {
                low=mid+1;
                mid=(low+high)/2;
            }
        }
        // cout<<low<<" "<<high<<" "<<mid<<endl;
        
        return mid;
    }
};