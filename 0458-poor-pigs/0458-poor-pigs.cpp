class Solution 
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) 
    {
        if(buckets==1)
        {
            return 0;
        }
        
        int rounds=minutesToTest/minutesToDie;
        
        int low=1;
        int high=buckets;
        int mid=(low+high)/2;
        
        int val=high;
        while(pow(rounds+1,val)>=buckets)
        {
            val--;
        }
        
        return val+1;
        
//         while(low<high)
//         {
//             if(pow(rounds+1,mid)>=buckets)
//             {
//                 high=mid-1;
//             }
//             else
//             {
//                 low=mid;
//             }
//             mid=(low+high)/2;
//         }
        
//         return mid+1; //getting TLE
    }
};