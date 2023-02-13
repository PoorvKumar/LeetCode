class Solution 
{
public:
    int countOdds(int low, int high) 
    {
        return high/2 + high%2 -low/2;
    }
};