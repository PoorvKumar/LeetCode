class Solution 
{
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n=points.size();
        
        //spanning tree is a tree having n nodes and n-1 edges
        int connections=0;
        
        priority_queue<pair<int,int>> pq;
        
        int i=0;
        
        vector<bool> visited(n,false);
        
        int ans=0;
        
        while(++connections<n)
        {
            visited[i]=true;
            
            for(int j=0; j<n; j++)
            {
                if(!visited[j])
                {
                    int val=-(abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]));
                    pq.push({val,j});  
                }
                
            }
            
            while(visited[pq.top().second])
            {
                pq.pop();
            }
            
            ans=ans-pq.top().first;
            i=pq.top().second;
            pq.pop();
        }
        
        return ans;
    }
};