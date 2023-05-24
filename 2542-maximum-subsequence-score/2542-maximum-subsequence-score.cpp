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
        
        sort(vec.begin(),vec.end()); //O(nlogn)
        
        // priority_queue<int> pq; //here instead of max heap we can implement min heap to remove the minimum element and find sum in less time
        
//         for(int i=n-1; i>n-k; i--)
//         {
//             pq.push(vec[i].second);
//         }
        
//         long long ans=0;
        
//         for(int i=n-k; i>=0; i--)
//         {
//             long long sum=vec[i].second;
//             // sum=sum+topKElem(pq,k); 
            
//             long long val=sum*vec[i].first;   
//             pq.push(vec[i].second); //O(logn)
            
//             ans=max(ans,val);
//         }
        
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