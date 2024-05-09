class Solution 
{
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) 
    {
        long long sum=0;
        int minusFactor=0;
        
        priority_queue<int> pq;
        
        for(auto x:happiness)
        {
            pq.push(x);
        }
        
        while(k--)
        {
            int val=pq.top()-(pq.top()>=minusFactor?minusFactor:pq.top());
            sum+=val;
            pq.pop();
            
            minusFactor++;
        }
        
        return sum;
    }
};