class Solution 
{
public:
    bool isUgly(int n) 
    {
        if(n<=0)
        {
            return false;
        }
        
        if(n==1)
        {
            return true;
        }
        
//         if(n%2==0 || n%3==0 || n%5==0)
//         {
//             if(n%2==0)
//             {
//                 return isUgly(n/2);
//             }
            
//             if(n%3==0)
//             {
//                 return isUgly(n/3);
//             }
            
//             return isUgly(n/5);
//         }
        
        if(n%2==0)
        {
            return isUgly(n/2);
        }
        
        if(n%3==0)
        {
            return isUgly(n/3);
        }
        
        if(n%5==0)
        {
            return isUgly(n/5);
        }
        
        return false;
    }
};