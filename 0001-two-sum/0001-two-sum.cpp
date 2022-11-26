class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> indices;
        for(int i=0; i<nums.size(); i++)
        {
            if(indices.count(target-nums[i]) && indices[target-nums[i]]!=i)
            {
                // return vector<int>({i,indices[target-nums[i]]});
                return {i,indices[target-nums[i]]}; //also works //and is faster as above first creates an object of type class vector
            }
            indices[nums[i]]=i;
        }
        
        return {1,2};
    }
};