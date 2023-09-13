class Solution 
{
public:
    int candy(vector<int>& ratings) 
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        int n=ratings.size();
        
        for(int i=0; i<n; i++)
        {
            pq.push({ratings[i],i});
        }
        
        vector<int> vec(n,1);
        
        while(!pq.empty())
        {
            pair<int,int> p=pq.top();
            pq.pop();
            
            int r=p.first;
            int i=p.second;
            
            if(i>0 && ratings[i-1]>r)
            {
                vec[i-1]=max(vec[i-1],vec[i]+1);
            }
            
            if(i<n-1 && ratings[i+1]>r)
            {
                vec[i+1]=max(vec[i+1],vec[i]+1);
            }
        }
        
        return accumulate(vec.begin(),vec.end(),0);
    }
};