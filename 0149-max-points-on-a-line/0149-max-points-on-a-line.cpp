class Solution 
{
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        if(points.size()==1)
        {
            return 1;
        }
        
        int ans=2;
        // unordered_map<double,int> umap;
        
        for(int i=0; i<points.size(); i++)
        {
            unordered_map<double,int> umap; //if max points lie on line with curr point 
            int x=points[i][0];
            int y=points[i][1];
            
            for(int j=i+1; j<points.size(); j++)
            {
                int a=points[j][0];
                int b=points[j][1];
                // double m=atan2(b-y,a-x);
                // umap[m]++;
                
                double m;
                if(a!=x)
                {
                    m=(double)(b-y)/(double)(a-x);
                    // m=atan2(b-y,a-x);
                }
                else
                {
                    m=10001;
                }
                umap[m]++;
            }
            
            for(auto p:umap)
            {
                ans=max(ans,p.second+1); //points on line = number of edges between points + 1
                // cout<<p.first<<" "<<p.second<<endl;
            }
        }
        
//         int ans=0;
        
//         for(auto x:umap)
//         {
//             ans=max(ans,x.second);
//             // cout<<x.first<<" "<<x.second<<endl;
//         }
        
//         // cout<<ans<<endl;
        
//         //can solve using quadratic formula
//         int x1=(1+pow(1+8*ans,0.5))/2;
//         // int x2=(1+pow(1-8*ans,0.5))/2;
        
//         return x1;
        
        return ans;
    }
};