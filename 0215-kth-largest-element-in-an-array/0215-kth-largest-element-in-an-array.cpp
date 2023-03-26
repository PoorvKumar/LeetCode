class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        // priority_queue<int> pq; //max heap
        priority_queue<int,vector<int>,greater<int>> pq1; //min heap
        
        int minim=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(pq1.size()<k)
            {
                // pq.push(nums[i]);
                pq1.push(nums[i]);
            }
            else
            {
                minim=pq1.top();
                if(nums[i]>minim)
                {
                    // pq.push(nums[i]);
                    pq1.push(nums[i]);
                    pq1.pop();
                    minim=pq1.top();
                }
            }
        }
        
        minim=pq1.top();
        return minim; //implemented only using min heap
    }
};