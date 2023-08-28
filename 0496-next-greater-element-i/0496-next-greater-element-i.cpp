class Solution 
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        stack<int> stk;
        unordered_map<int,int> umap;
        
        stk.push(nums2[0]);
        
        for(int i=1; i<nums2.size(); i++)
        {
            while(!stk.empty() && stk.top()<nums2[i])
            {
                umap[stk.top()]=nums2[i];
                stk.pop();
            }
            
            stk.push(nums2[i]);
        }
        
        for(auto &x:nums1)
        {
            if(umap.count(x))
            {
                x=umap[x];
            }
            else
            {
                x=-1;
            }
        }
        
        return nums1;
    }
};