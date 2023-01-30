class Solution 
{
private:
    unordered_map<int,vector<int>> adjList;
    string s;
    
    int longestPathUtil(int src,int& maxim)
    {
        if(!adjList.count(src))
        {
            return 1;
        }
        
        int path=0;
        int p1=0; //curent branch
        int p2=0; //next branch
        
        for(int i=0; i<adjList[src].size(); i++)
        {
            int node=adjList[src][i];
            int x=longestPathUtil(node,maxim);
            
            maxim=max(maxim,x);
            
            if(s[src]!=s[node])
            {
                path=path+x;
                if(x>p1)
                {
                    p2=p1;
                    p1=x;
                }
                else
                {
                    p2=max(x,p2);
                }
            }
        }
        
        maxim=max(maxim,1+p1+p2);
//         if(path!=0) //this does not work but above works need to see why
//         {
//             path++;
//         }
        
//         maxim=max(maxim,path);        
//         return maxim; //cannot return maxim; on every call 
        
        return p1+1; // return 1+currPath; for a call which is longestPath for the subTree 
        
        // maxim=max(maxim,1+p1+p2);
        // return 1+p1;
    }
public:
    int longestPath(vector<int>& parent, string s) 
    {
        if(parent.size()==1)
        {
            return 1;
        }
        
        for(int i=1; i<parent.size(); i++)
        {
            adjList[parent[i]].push_back(i);
        }
        
        this->s=s;
        
        int maxim=0;
        // return longestPathUtil(0,maxim);
        longestPathUtil(0,maxim);
        return maxim;
    }
};