class Solution 
{
public:
    vector<int> sortByBits(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        
        map<int,vector<int>> mp;
        
        for(int i=0; i<arr.size(); i++)
        {
            bitset<32> bt(arr[i]);
            
            mp[bt.count()].push_back(i);
        }
        
        vector<int> res;
        for(auto x:mp)
        {
            for(auto y:x.second)
            {
                res.push_back(arr[y]);
            }
        }
        
        return res;
    }
};