class Solution 
{
public:
    int longestSubarray(vector<int>& nums) 
    {
        vector<int> vec;
        
        int count=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i])
            {
                count++;
            }
            else
            {
                if(count)
                {
                    vec.push_back(count);
                }
                count=0;
                vec.push_back(count);
            }
        }
        
        if(count)
        {
            vec.push_back(count);
        }
        
        // for(auto x:vec)
        // {
        //     cout<<x<<" ";
        // }
        
        if(vec.size()==1)
        {
            return vec[0]-1;
        }
        
        int ans=0;
        
        for(int i=0; i<vec.size(); i++)
        {
            if(vec[i]==0)
            {
                int val=0;
                if(i>0)
                {
                    val=val+vec[i-1];
                }
                if(i<vec.size()-1)
                {
                    val=val+vec[i+1];
                }
                
                ans=max(ans,val);
            }
        }
        
        return ans;
    }
};