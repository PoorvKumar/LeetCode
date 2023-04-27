class Solution 
{
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        unordered_map<int,int> umap;
        
        stack<int> stk;
        
        int n=nums.size();
        
        for(int i=0; i<n; i++)
        {
            nums.push_back(nums[i]);
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            while(!stk.empty() && nums[stk.top()]<nums[i])
            {
                if(!umap.count(stk.top()))
                {
                    umap[stk.top()]=nums[i];
                }
                stk.pop();
            }
            stk.push(i);
        }
        
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i]>nums[nums.size()-1])
            {
                umap[nums.size()-1]=nums[i];
                break;
            }
        }
        
        vector<int> ans(n,-1);
        for(int i=0; i<n; i++)
        {
            if(umap.count(i))
            {
                ans[i]=umap[i];
            }
        }
        
        return ans;
    }
};