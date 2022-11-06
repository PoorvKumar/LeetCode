class Solution {
public:
    bool isPowerOfFour(int n) 
    {
        if(n==1 || n==0) //Base Case
        {
            if(n==0)
            {
                return false;
            }
            return true;
        }
        
        if(n%4==0) //Recursive Step //Recursive
        {
            return isPowerOfFour(n/4); 
        }
        return false;
    }
};