class Solution {
public:
    bool isHappy(int n) 
    {
//         if(n==1 || n==7) //failed test case for n==7 so added here ckeckeed for other single digit->works
//         {
//             return true;
//         }
//         if(n%10==n)
//         {
//             return false;
//         }
        
//         int sum=0;
//         do
//         {
//             sum=sum+pow((n%10),2);
//             n=n/10;
//         }
//         while(n>0);
        
//         return isHappy(sum);
        
        if(n==1 || n==7)  //interesting two-pointer approach
        {
            return true;
        }
        
        int slow=square(n);
        int fast=square(slow);
        
        while(slow!=fast)
        {
            slow=square(slow);
            fast=square(square(fast));
        }
        
        return slow==1;
    }
    
    int square(int n)
    {
        int sum=0;
        do
        {
            sum=sum+pow((n%10),2);
            n=n/10;
        }
        while(n>0);
        
        return sum;
    }
};