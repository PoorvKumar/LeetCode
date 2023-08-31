class Solution 
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        stack<pair<int,int>> stk;
        stk.push({nums2[0],0});
        
        unordered_map<int,int> umap;
        
        // vector<int> vec(nums2.size(),-1);
        
        for(int i=1; i<nums2.size(); i++)
        {
            while(!stk.empty() && stk.top().first<nums2[i])
            {
                // vec[stk.top().second]=i;
                umap[stk.top().first]=nums2[i];
                stk.pop();
            }
            stk.push({nums2[i],i});
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