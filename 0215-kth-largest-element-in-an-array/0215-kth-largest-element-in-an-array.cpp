class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int,vector<int>,greater<int>> pq; //min heap
        
        for(auto x:nums)
        {
            if(pq.size()<k)
            {
                pq.push(x);
            }
            else if(pq.top()<=x)
            {
                pq.pop();
                pq.push(x);
            }
        }
        
        return pq.top(); //Optimized Approach
        //TC: O(nlogk) //as for every index insertion takes O(logk) time complexity
        //SC: O(k)
    }
};