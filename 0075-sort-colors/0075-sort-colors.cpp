class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        // sort(begin(nums),nums.end());
        
        for(int i=0; i<nums.size(); i++) //Selection Sort
        {
            int minimIndex=i;
            for(int j=i+1; j<nums.size(); j++)
            {
                if(nums[j]<nums[minimIndex])
                {
                    minimIndex=j;
                }
            }
            // int minimIndex=min_element(begin(nums)+i,end(nums))-nums.begin();
            
            swap(nums[i],nums[minimIndex]);
        }
    }
};