class Solution 
{
public:
    int arraySign(vector<int>& nums) 
    {
        int pos=0;
        int neg=0;
        
        for(auto x:nums)
        {
            if(x==0)
            {
                return 0;
            }
            
            x<0?neg++:pos++;
        }
        
        return neg%2==0?1:-1;
    }
};