class Solution 
{
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        heights.push_back(0);
        int n=heights.size();
        
        int ans=0;
        stack<pair<int,int>> stk;
        
        for(int i=0; i<n; i++)
        {
            while(!stk.empty() && stk.top().first>heights[i])
            {
                int right=i;
                int h=stk.top().first;
                
                stk.pop();
                
                int left=stk.empty()?-1:stk.top().second;
                int area=h*(right-left-1);
                
                ans=max(ans,area);
            }
            
            stk.push({heights[i],i});
        }
        
        return ans;
    }
};