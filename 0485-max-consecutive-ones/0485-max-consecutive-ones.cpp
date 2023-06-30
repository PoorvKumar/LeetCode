class Solution 
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int ans=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i])
            {
                int j=i+1;
                while(j<nums.size() && nums[j]==1)
                {
                    j++;
                }
                
                ans=max(ans,j-i);
                i=j-1;
            }
        }
        
        return ans; 
        //TC: O(n)
        //SC: O(1)
    }
};