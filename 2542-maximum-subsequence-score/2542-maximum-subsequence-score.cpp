class Solution 
{
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        vector<pair<int,int>> vec;
        
        int n=nums1.size();
        
        for(int i=0; i<n; i++)
        {
            vec.push_back(make_pair(nums2[i],nums1[i]));
        }
        
        sort(vec.begin(),vec.end());
        
        priority_queue<int,vector<int>,greater<int>> pq; //MIN HEAP
        
        long long sum=0;
        long long ans=0;
        
        for(int i=n-1; i>=0; i--)
        {
            pq.push(vec[i].second);
            sum=sum+vec[i].second;
            
            if(pq.size()>k)
            {
                sum=sum-pq.top();
                pq.pop();
            }
            
            if(pq.size()==k)
            {
                ans=max(ans,(long long)(vec[i].first*sum));
            }
        }
        
        return ans;
    }
};