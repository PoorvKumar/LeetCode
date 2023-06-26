class Solution 
{
public:
    long long totalCost(vector<int>& costs, int k, int candidates) 
    {
        priority_queue<int,vector<int>,greater<int>> rpq;
        priority_queue<int,vector<int>,greater<int>> lpq;
        
        int n=costs.size();
        
        int i;
        for(i=0; i<candidates && i<n; i++)
        {
            lpq.push(costs[i]);
        }
        
        int left=i-1;
        
        for(i=0; i<candidates && n-1-i>left; i++)
        {
            rpq.push(costs[n-1-i]);
        }
        
        int right=n-i;
        // cout<<left<<" "<<right<<endl;
        
        long long ans=0;
        
        while(k--)
        {
            // cout<<costs[left]<<" "<<costs[right]<<endl;
            if(!lpq.empty() && (rpq.empty() || lpq.top()<=rpq.top()))
            {
                ans=ans+lpq.top();
                lpq.pop();
                
                if(left<right-1)
                {
                    lpq.push(costs[++left]);
                }
            }
            else
            {
                ans=ans+rpq.top();
                rpq.pop();
                
                if(right>left+1)
                {
                    rpq.push(costs[--right]);
                }
            }
        }
        
        return ans; //MIN HEAP using an object of type class priority_queue<int,vector<int>,greater<int>>
        //TC: O(nlogn)
        //SC: O(n)
    }
};