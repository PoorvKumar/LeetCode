class Solution 
{
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n=heights.size();
        stack<pair<int,int>> stk;
        
        vector<int> left(n,-1);
        vector<int> right(n,n);
        
        //finding nse to right
        for(int i=0; i<n; i++)
        {
            while(!stk.empty() && stk.top().first>heights[i])
            {
                right[stk.top().second]=i;
                stk.pop();
            }
            
            stk.push({heights[i],i});
        }
        
        while(!stk.empty())
        {
            stk.pop();
        }
        
        //finding nse to left
        for(int i=n-1; i>=0; i--)
        {
            while(!stk.empty() && stk.top().first>heights[i])
            {
                left[stk.top().second]=i;
                stk.pop();
            }
            
            stk.push({heights[i],i});
        }
        
        int ans=heights[0];
        
        for(int i=0; i<n; i++)
        {
            int area=heights[i]*(right[i]-left[i]-1);
            ans=max(ans,area);
        }
        
        return ans;
    }
};