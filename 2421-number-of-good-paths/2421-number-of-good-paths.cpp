class Solution 
{
private:
    int find_parent(vector<int>& parent,int i)
    {
        if(parent[i]==i)
        {
            return parent[i];
        }
        parent[i]=find_parent(parent,parent[i]);
        return parent[i];
    }
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) 
    {
        int n=edges.size()+1;
        
        vector<int> parent(n);
        vector<vector<int>> freqVal;
        
        for(int i=0; i<n; i++)
        {
            parent[i]=i;
            freqVal.push_back({vals[i],1});
        }
        
        auto compareEdges=[&](vector<int>& x,vector<int>& y)->bool{return max(vals[x[0]],vals[x[1]])<max(vals[y[0]],vals[y[1]]);};
        
        sort(edges.begin(),edges.end(),compareEdges);
        
        // for(auto x:edges)
        // {
        //     for(auto y:x)
        //     {
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        
        int res=0;
        res=res+n;
        
        for(int i=0; i<edges.size(); i++)
        {
            int x=find_parent(parent,edges[i][0]);
            int y=find_parent(parent,edges[i][1]);
            
            if(vals[x]!=vals[y])
            {
                if(vals[x]>vals[y])
                {
                    parent[y]=x;
                }
                else
                {
                    parent[x]=y;
                }
            }
            else
            {
                parent[x]=y;
                res=res+freqVal[x][1]*freqVal[y][1];
                freqVal[y][1]=freqVal[y][1]+freqVal[x][1];
            }
        }
        
        return res;
    }
};

