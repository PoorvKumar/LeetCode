class Solution 
{
public:
    int pivotInteger(int n) 
    {
        int sum=0;
        
        int i=n;
        
        while(i>0)
        {
            int lsum=(i*(i+1))/2;
            sum+=i;
            
            if(lsum==sum)
            {
                return i;
            }
            
            i--;
        }
        
        return -1;
    }
};