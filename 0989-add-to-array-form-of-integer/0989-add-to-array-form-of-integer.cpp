class Solution 
{
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) 
    {
        vector<int> vec;
        while(k>0)
        {
            vec.push_back(k%10);
            k=k/10;
        }
        
        reverse(nums.begin(),nums.end());
        
        if(nums.size()<vec.size())
        {
            nums.swap(vec);
        }
        
        int i=0;
        int sum=0;
        int carry=0;
        
        while(i<vec.size() && i<nums.size())
        {
            sum=nums[i]+vec[i]+carry;
            carry=sum/10;
            sum=sum%10;
            
            nums[i]=sum;
            
            i++;
        }
        
        while(i<nums.size())
        {
            sum=nums[i]+carry;
            carry=sum/10;
            sum=sum%10;
            
            nums[i]=sum;
            
            i++;
        }
        
        if(carry!=0)
        {
            nums.push_back(carry);
        }
        
        reverse(nums.begin(),nums.end());
        
        return nums;
    }
};
