class Solution 
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        stack<int> stk; //monotonic increasing stack
        unordered_map<int,int> umap;
        
        for(int i=0; i<nums2.size(); i++) //TC:O(n+m) //SC:O(m)
        {
            if(stk.empty())
            {
                stk.push(nums2[i]);
                continue;
            }
            
            if(stk.top()<nums2[i])
            {
                if(!umap.count(stk.top()))
                {
                    umap[stk.top()]=nums2[i]; //
                }
                stk.push(nums2[i]);
            }
            else
            {
                if(!umap.count(stk.top())) //finding NGE for element on top of stack
                {
                    int j=i+1;
                    while(j<nums2.size())
                    {
                        if(stk.top()<nums2[j])
                        {
                            umap[stk.top()]=nums2[j];
                            break;
                        }
                        j++;
                    }
                }
                
                while(!stk.empty() && stk.top()>nums2[i]) 
                {
                    stk.pop(); //popping elements form stack to make it monotonic increasing
                }
                
                stk.push(nums2[i]);
            }
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
        
        return nums1; //TC: O(n+m) SC: O(m)
    }
};