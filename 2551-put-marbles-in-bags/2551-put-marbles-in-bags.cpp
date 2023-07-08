class Solution 
{
public:
    long long putMarbles(vector<int>& weights, int k) 
    {
        priority_queue<long long> pq;
        priority_queue<long long,vector<long long>,greater<long long>> pq1;
        
        for(int i=0; i<weights.size()-1; i++)
        {
            long long val=weights[i]+weights[i+1];
            pq.push(val);
            pq1.push(val);
        }
        
        if(weights.size()<k)
        {
            k=weights.size();
        }
        
        k--;
        
        long long maxim=0;
        long long minim=0;
        
        while(k--)
        {
            maxim=maxim+pq.top();
            pq.pop();
            minim=minim+pq1.top();
            pq1.pop();
        }
        
        return maxim-minim;
    }
};