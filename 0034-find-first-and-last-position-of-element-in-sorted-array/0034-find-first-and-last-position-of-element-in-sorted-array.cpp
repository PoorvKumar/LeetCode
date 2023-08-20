class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> res;
        
        if(nums.empty())
        {
            return res={-1,-1};
        }
        
        auto lit=lower_bound(nums.begin(),end(nums),target);
        res.push_back((lit==nums.end() || *lit!=target?-1:lit-begin(nums)));
        
        auto uit=upper_bound(nums.begin(),nums.end(),target);
        if(uit==begin(nums) || *prev(uit)!=target)
        {
            res.push_back(-1);
        }
        else
        {
            res.push_back(uit-nums.begin()-1);
        }
        
        return res;
    }
};