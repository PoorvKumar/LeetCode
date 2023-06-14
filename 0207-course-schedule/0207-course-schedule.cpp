class Solution 
{
private:
    unordered_map<int,vector<int>> adjList;
    // vector<vector<int>> adjList;
    
    vector<bool> visited;
    
    bool canFinishUtil(int src,unordered_set<int>& path)
    {
        visited[src]=true;
        path.insert(src);
        
        for(auto node:adjList[src])
        {
            if(!visited[node])
            {
                bool res=canFinishUtil(node,path);
                if(!res)
                {
                    return false;
                }
            }
            else
            {
                if(path.count(node))
                {
                    // cout<<src<<" "<<node<<endl;
                    return false;
                }
            }
        }
        
        path.erase(src);
        
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        visited.assign(numCourses,false);
        
        // adjList.assign(numCourses,vector<int>());
        
        for(auto x:prerequisites)
        {
            adjList[x[1]].push_back(x[0]);
        }
        
        // for(auto x:adjList)
        // {
        //     cout<<x.first<<" -> ";
        //     for(auto y:x.second)
        //     {
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        
        unordered_set<int> path;
        
        auto it=find(begin(visited),visited.end(),false);
        
        while(it!=end(visited)) //dealt with components of graph this way  
        {                        //instead of calling inside dfs() function as it causes error in path
            path.clear();
            bool res=canFinishUtil(it-visited.begin(),path);
            if(!res)
            {
                return false;
            }
            
            it=find(begin(visited),visited.end(),false);
        }
        
        // return canFinishUtil(0,path);
        return true;
    }
};