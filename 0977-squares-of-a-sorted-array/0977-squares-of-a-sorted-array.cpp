class Solution 
{
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int zIndex=-1; //index of first non-negative
        
        for(int i=0; i<nums.size(); i++)
        {
            zIndex=i;
            if(nums[i]>=0)
            {
                break;
            }
        }
        
        //zIndex==nums.size()
        
        int left=zIndex-1;
        int right=zIndex;
        
        vector<int> vec;
        
        while(left>=0 || right<nums.size())
        {
            if(left<0)
            {
                vec.push_back(nums[right]*nums[right]);
                right++;
                continue;
            }
            
            if(right>=nums.size())
            {
                vec.push_back(nums[left]*nums[left]);
                left--;
                continue;
            }
            
            if(abs(nums[left])<=nums[right])
            {
                vec.push_back(nums[left]*nums[left]);
                left--;
            }
            else
            {
                vec.push_back(nums[right]*nums[right]);
                right++;
            }
        }
        
        return vec;
    }
};