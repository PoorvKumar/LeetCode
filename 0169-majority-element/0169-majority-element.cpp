class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());  //O(nlogn)
        
        return nums[nums.size()/2];
    }
};