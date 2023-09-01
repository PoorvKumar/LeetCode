class Solution 
{
public:
    vector<int> countBits(int n) 
    {
        vector<int> res;
        
        for(int i=0; i<=n; i++)
        {
            bitset<32> bs(i);
            res.push_back(bs.count());
        }
        
        return res;
    }
};