class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> res;
        
        if(nums.empty())
        {
            return vector<int>({-1,-1});
        }
        
        auto lit=lower_bound(nums.begin(),end(nums),target);
        int l=lit-begin(nums);
        
        if(lit==nums.end() || nums[l]!=target)
        {
            l=-1;
        }
        res.push_back(l);
        
        vector<int>::iterator rit=upper_bound(begin(nums),nums.end(),target);
        int r=rit-nums.begin()-1;
        if(rit==nums.begin() || *prev(rit)!=target)
        {
            r=-1;
        }
        
        res.push_back(r);
        
        return res;
    }
};