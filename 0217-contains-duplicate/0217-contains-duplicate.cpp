class Solution {
public:    
    bool containsDuplicate(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end()); //O(nlogn)
        
        for(int i=0; i<nums.size()-1; i++) ///O(n)
        {
            if(nums[i]==nums[i+1])
            {
                return true;
            }
        }
        
        return false;
        
//         set<int> set(nums.begin(),nums.end()); //More time complexity
        
//         return nums.size()!=set.size();
    }
};