class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        priority_queue<pair<int,int>> pq;
        
        vector<int> res;
        
        for(int i=0; i<k; i++)
        {
            pq.push({nums[i],i});
        }
        
        res.push_back(pq.top().first);
        
        for(int i=k; i<nums.size(); i++)
        {
            pq.push({nums[i],i});
            
            int j=pq.top().second;
            while(j<=i-k)
            {
                pq.pop();
                j=pq.top().second;
            }
            
            int val=pq.top().first;
            res.push_back(val);
        }
        
        return res;
    }
};