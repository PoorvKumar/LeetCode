class Solution
{
public:
    vector<int> findArray(vector<int>& pref)
    {
        vector<int> res;
        res.push_back(pref.front());
        
        for(int i=1; i<pref.size(); i++)
        {
            bitset<32> bs1(pref[i-1]);
            bitset<32> bs2(pref[i]);
            
            bitset<32> bs(0);
            
            for(int i=0; i<32; i++)
            {
                if(bs2[i]==1)
                {
                    bs[i]=!bs1[i];
                }
                else
                {
                    bs[i]=bs1[i];
                }
            }
            
            int val=(int)bs.to_ulong();
            res.push_back(val);
        }
        
        return res;
    }
};