class Solution 
{
public:
    string findDifferentBinaryString(vector<string>& nums) 
    {
        unordered_set<int> uset;
        
        for(auto x:nums)
        {
            bitset<32> bs(x);
            int val=bs.to_ulong();
            uset.insert(val);
        }
        
        int n=nums.size();
        
        for(int i=0; i<pow(2,n); i++)
        {
            if(!uset.count(i))
            {
                bitset<16> bs(i);
                string res=bs.to_string();
                res=res.substr(16-n);
                
                return res;
            }
        }
        
        return "";
    }
};