/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution 
{
public:
    long long guessNumber(int n) 
    {
        long long low=1;
        long long high=n;
        
        long long mid=(low+high)/2;
        
        while(low<high)
        {
            int x=guess(mid);
            
            if(x==0)
            {
                return mid;
            }
            else if(x==1)
            {
                low=mid+1;
                mid=(low+high)/2;
            }
            else
            {
                high=mid-1;
                mid=(low+high)/2;
            }
        }
        
        return low;
    }
};