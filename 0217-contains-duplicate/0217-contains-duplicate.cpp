class Solution {
public:    
    bool containsDuplicate(vector<int>& nums) 
    {
        // selectionSort(nums);
//         sort(nums.begin(),nums.end());
        
//         for(int i=0; i<nums.size()-1; i++)
//         {
//             if(nums[i]==nums[i+1])
//             {
//                 return true;
//             }
//         }
        
//         return false;
        
        set<int> set(nums.begin(),nums.end());
        
        return nums.size()!=set.size();
    }
};